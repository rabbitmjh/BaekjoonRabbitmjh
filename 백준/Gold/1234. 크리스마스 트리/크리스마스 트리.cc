#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, r, g, b, dp[15][60][60][60], facto[15];

ll go(int lv, int R, int G, int B) {
	if (lv > n)return 1;

	if (dp[lv][R][G][B] != -1)return dp[lv][R][G][B];
	dp[lv][R][G][B] = 0;

	//1가지
	if (r - R >= lv)dp[lv][R][G][B] += go(lv + 1, R + lv, G, B);
	if (g - G >= lv)dp[lv][R][G][B] += go(lv + 1, R, G + lv, B);
	if (b - B >= lv)dp[lv][R][G][B] += go(lv + 1, R, G, B + lv);

	//2가지
	if (lv % 2 == 0) {
		ll div = facto[lv] / facto[lv / 2] / facto[lv / 2];
		if (r - R >= lv / 2 && g - G >= lv / 2)//R,G사용
			dp[lv][R][G][B] += div * go(lv + 1, R + lv / 2, G + lv / 2, B);
		if (b - B >= lv / 2 && g - G >= lv / 2)//G,B사용
			dp[lv][R][G][B] += div * go(lv + 1, R, G + lv / 2, B + lv / 2);
		if (r - R >= lv / 2 && b - B >= lv / 2)//B,R사용
			dp[lv][R][G][B] += div * go(lv + 1, R + lv / 2, G, B + lv / 2);
	}

	//3가지
	if (lv % 3 == 0 && r - R >= lv / 3 && g - G >= lv / 3 && b - B >= lv / 3)
		dp[lv][R][G][B] += (facto[lv] / facto[lv / 3] / facto[lv / 3] / facto[lv / 3]) *
		go(lv + 1, R + lv / 3, G + lv / 3, B + lv / 3);

	return dp[lv][R][G][B];
}


int main() {
	FIO;
	cin >> n >> r >> g >> b;

	memset(dp, -1, sizeof(dp));
	facto[0] = 1;
	for (int i = 1; i <= n; i++)
		facto[i] = facto[i - 1] * i;

	cout << go(1, 0, 0, 0);

	return 0;
}
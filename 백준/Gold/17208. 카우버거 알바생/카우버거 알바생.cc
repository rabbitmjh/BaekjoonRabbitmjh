#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, k, arr[105][305][305];
int c[105], f[105];

int dp(int now, int ch, int fr) {
	if (now == n)return 0;
	if (arr[now][ch][fr] >= 0)
		return arr[now][ch][fr];

	int tmp = 0;
	if (c[now] <= ch && f[now] <= fr)
		tmp = dp(now + 1, ch - c[now], fr - f[now]) + 1;

	tmp = max(tmp, dp(now + 1, ch, fr));
	return arr[now][ch][fr] = tmp;
}

int main() {
	FIO;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m; j++)
			for (int q = 0; q <= k; q++)
				arr[i][j][q] = -1;

	for (int i = 0; i < n; i++)
		cin >> c[i] >> f[i];

	cout << dp(0, m, k);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

#define mod 100000;
int w, h, ans, dp[105][105][2][2];

int main() {
	FIO;
	cin >> w >> h;
	for (int i = 2; i <= w; i++)
		dp[i][1][0][0] = 1;
	for (int i = 2; i <= h; i++)
		dp[1][i][1][0] = 1;


	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % mod;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % mod;
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans = (dp[w][h][i][j] + ans) % mod;

	cout << ans;

	return 0;
}
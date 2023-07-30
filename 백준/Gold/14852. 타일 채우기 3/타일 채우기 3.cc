#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, dp[1000005][2];
static int mod = 1000000007;

int main() {
	FIO;
	cin >> n;

	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;
	dp[3][0] = 22;
	for (int i = 3;i <= n;i++) {
		dp[i][1] = (dp[i - 3][0] + dp[i - 1][1]) % mod;
		dp[i][0] = (3 * dp[i - 2][0] % mod + 2 * dp[i - 1][0] % mod + 2 * dp[i][1] % mod) % mod;
	}
	cout << dp[n][0];

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k, dp[205][205];
ll ans;
#define mod 1000000000;

int main() {
	FIO;
	cin >> n >> k;
	for (int i = 0;i <= n;i++)
		dp[1][i] = 1;

	for (int i = 2;i <= k;i++) {
		int tmp = 0;

		for (int j = 0;j <= n;j++) {
			tmp = (tmp + dp[i - 1][j]) % mod;
			dp[i][j] = tmp;
		}
	}
		
	cout << dp[k][n] % mod;

	return 0;
}
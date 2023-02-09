#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, dp[55][55], ans;

int main() {
	FIO;
	
	cin >> n;
	for (int i = 0; i <= 52; i++) {
		dp[i][0] = 1;

		if (i > 0)
			for (int j = 1; j <= 52; j++)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
	}

	for (int i = 1; i <= 13; i++) {
		if (n - 4 * i < 0)break;

		if (i % 2 == 0)
			ans -= ((dp[52 - 4 * i][n - 4 * i] * dp[13][i]) % 10007) % 10007;
		else
			ans += ((dp[52 - 4 * i][n - 4 * i] * dp[13][i]) % 10007) % 10007;
		ans %= 10007;
	}

	if (ans < 0)ans += 10007;
	cout << ans % 10007;

	return 0;
}
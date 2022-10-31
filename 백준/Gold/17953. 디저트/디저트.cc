#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <cmath>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, dp[100005][15], arr[100005][15], ans, last = -1, cur;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[j][i];
	
	if (n == 1) {
		for (int i = 1; i <= m; i++)
			ans = max(ans, arr[1][i]);
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= m; i++)
		dp[1][i] = arr[1][i];
	
	for (int i = 2; i <= n; i++) {
		int mx = 0, sum = 0;

		for (int j = 1; j <= m; j++) {
			int next1 = dp[i][j];

			for (int k = 1; k <= m; k++) {
				int next2 = arr[i][k];
				if (j == k)
					next2 /= 2;

				dp[i][k] = max(dp[i][k], next2 + dp[i - 1][j]);
			}
		}
	}

	for (int i = 1; i <= m; i++)
		ans = max(ans, dp[n][i]);
	cout << ans;
	return 0;
} 
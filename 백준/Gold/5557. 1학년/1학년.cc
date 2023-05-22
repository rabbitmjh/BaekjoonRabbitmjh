#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[105];
ll dp[21][105];

int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	dp[arr[0]][0] = 1;
	for (int i = 1;i < n;i++) {
		int now = arr[i];
		for (int j = 0;j <= 20;j++) {
			if (dp[j][i - 1] > 0) {
				int nextP = j + now;
				int nextM = j - now;

				if (nextP <= 20)
					dp[nextP][i] += dp[j][i - 1];
				if (nextM >= 0)
					dp[nextM][i] += dp[j][i - 1];
			}
		}
	}

	cout << dp[arr[n - 1]][n - 2];
	return 0;
}
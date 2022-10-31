#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k, arr[105][100005], w[105], v[105];

int main() {
	FIO;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w[i] > -1)
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - w[i]] + v[i]);
			else
				arr[i][j] = arr[i - 1][j];
		}
	}
	cout << arr[n][k];

	return 0;
}
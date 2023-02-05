#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k, arr[1005][10005];
p v[1005];

int main() {
	FIO;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int a, b; cin >> a >> b;
		v[i].first = a;
		v[i].second = b;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i].second <= j)
				arr[i][j] = max(arr[i - 1][j], v[i].first + arr[i - 1][j - v[i].second]);
			else
				arr[i][j] = arr[i - 1][j];
		}
	}
	cout << arr[k][n];
	return 0;
}
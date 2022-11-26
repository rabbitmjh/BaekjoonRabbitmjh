#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, arr[105][105], t = 2;

int main() {
	FIO;
	cin >> n >> m;
	while (t--) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int a; cin >> a;
				if (t == 2)arr[i][j] = a;
				else arr[i][j] += a;
			}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
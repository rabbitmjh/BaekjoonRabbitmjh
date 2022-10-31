#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, sum[100005];

int main() {
	FIO;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		if (i)
			sum[i] = sum[i - 1] + sum[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}

	return 0;
}
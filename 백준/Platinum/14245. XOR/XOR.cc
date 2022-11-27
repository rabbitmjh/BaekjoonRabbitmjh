#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;
typedef pair<int, p> pp;

int n, m, arr[500005];

void update(int i, int val) {
	for (; i <= n; i += i & -i)
		arr[i] ^= val;
}
 int query(int i) {
	int sum = 0;
	for (; i; i -= i & -i)
		sum ^= arr[i];
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		update(i + 1, a);
		update(i + 2, a);
	}

	cin >> m;
	while (m--) {
		int x; cin >> x;

		if (x == 2) {
			int a; cin >> a;
			cout << query(a + 1) << "\n";
		}
		else {
			int a, b, c; cin >> a >> b >> c;
			update(a + 1, c);
			update(b + 2, c);
		}
	}

	return 0;
}
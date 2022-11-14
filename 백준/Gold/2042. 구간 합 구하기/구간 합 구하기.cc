#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, m, k;
vector <ll> v, tree;

ll sum(int i) {
	int idx = i;
	ll ans = 0;
	while (idx > 0) {
		ans += tree[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int i, ll diff) {
	int idx = i;
	while (idx < tree.size()) {
		tree[idx] += diff;
		idx += idx & -idx;
	}
}

int main() {
	FIO;
	cin >> n >> m >> k;
	v.resize(n + 5);
	tree.resize(n + 5);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		update(i, v[i]);
	}
	
	m += k;
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - v[b];
			v[b] = c;
			update(b, diff);
		}
		else {
			cout << sum(c) - sum(b - 1) << "\n";
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, m, k;
vector <ll> v(1000010), tree(1000010);

ll sum(int i) {
	int idx = i;
	ll ans = 0;
	while (idx > 0) {
		ans += tree[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int i, int val) {
	int idx = i;
	while (idx < n + 1) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int main() {
	FIO;
	cin >> n >> m;
	
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (a) {
			update(b, c - v[b]);
			v[b] = c;
		}
		else {
			if (b > c)
				swap(b, c);
			cout << sum(c) - sum(b - 1) << "\n";
		}
	}
	
	return 0;
}
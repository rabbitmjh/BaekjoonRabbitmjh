#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;
typedef pair<int, p> pp;

int n, m, k, h = 1;
vector <ll> seg, lazy;

void update(int idx, ll val) {
	idx += h - 1;
	seg[idx] += val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}
void propagation(int node, int l, int r) {
	if (lazy[node] == 0)return;
	seg[node] += lazy[node] * (r - l + 1);
	if (r != l) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void query_lazy(int L, int R, int node, int l, int r, ll val) {
	propagation(node, l, r);
	if (r < L || R < l) return;
	if (L <= l && r <= R) {
		seg[node] += val * (r - l + 1);
		if (l != r) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (l + r) / 2;
	query_lazy(L, R, node * 2, l, mid, val);
	query_lazy(L, R, node * 2 + 1, mid + 1, r, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int l, int r, int node, int nodeL, int nodeR) {
	propagation(node, nodeL, nodeR);
	if (r < nodeL || nodeR < l) return 0;
	if (l <= nodeL && nodeR <= r) return seg[node];
	int mid = (nodeL + nodeR) / 2;
	return query(l, r, node * 2, nodeL, mid) + query(l, r, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;

	while (n > h)
		h <<= 1;
	lazy.resize(h * 2);
	seg.resize(h * 2);

	for (int i = 1; i <= n; i++) {
		ll num; cin >> num;
		update(i, num);
	}
	for (int i = 1; i <= m + k; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c;  ll d;
			cin >> b >> c >> d;
			query_lazy(b, c, 1, 1, h, d);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << query(b, c, 1, 1, h) << "\n";
		}
	}
	return 0;
}
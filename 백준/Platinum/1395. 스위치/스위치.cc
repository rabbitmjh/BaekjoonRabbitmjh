#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;
typedef pair<int, p> pp;

vector<int> seg;
vector<int> lazy;

void lazyUpdate(int l, int r, int node) {
	if (lazy[node] % 2 == 1) { 
		seg[node] = (r - l + 1) - seg[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void query(int l, int r, int nodeL, int nodeR, int node) {
	lazyUpdate(l, r, node);
	if (nodeR < l || r < nodeL)
		return;

	if (nodeL <= l && r <= nodeR) {
		seg[node] = (r - l + 1) - seg[node];
		if (l != r) {
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
		return;
	}

	int mid = (l + r) / 2;
	query(l, mid, nodeL, nodeR, node * 2);
	query(mid + 1, r, nodeL, nodeR, node * 2 + 1);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
	return;
}

int sum(int l, int r, int nodeL, int nodeR, int node) {
	lazyUpdate(l, r, node);
	if (nodeR < l || r < nodeL)
		return 0;

	if (nodeL <= l && r <= nodeR)
		return seg[node];

	int mid = (l + r) / 2;
	return sum(l, mid, nodeL, nodeR, node * 2) + sum(mid + 1, r, nodeL, nodeR, node * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	int h = (int)ceil(log2(n));
	seg = vector<int>(1 << (h + 1));
	lazy = vector<int>(1 << (h + 1));

	int o, s, t;
	while (m--) {
		cin >> o >> s >> t;
		if (o == 0)
			query(1, n, s, t, 1);
		else
			cout << sum(1, n, s, t, 1) << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<p, int> pp;

ll h, q, r, n = 1;
vector <ll> v;
vector <double> seg, lazy;

void update(int num, double val) {
	num += n - 1;
	seg[num] += val;
	while (num > 1) {
		num /= 2;
		seg[num] = seg[num * 2] + seg[num * 2 + 1];
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

void query_lazy(int L, int R, int node, int l, int r, double val) {
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

double query(int l, int r, int node, int nodeL, int nodeR) {
	propagation(node, nodeL, nodeR);
	if (r < nodeL || nodeR < l) return 0;
	if (l <= nodeL && nodeR <= r) return seg[node];
	int mid = (nodeL + nodeR) / 2;
	return query(l, r, node * 2, nodeL, mid) + query(l, r, node * 2 + 1, mid + 1, nodeR);
}

int main(){
	FIO;
	cin >> h >> q >> r;
	while (n < h + 1)
		n <<= 1;
	seg.resize(n * 4); lazy.resize(n * 4);
	v.push_back(0);
	for (int i = 1;i <= h;i++)
		v.push_back(i + v.back());

	while (q--) {
		ll a;double b;
		cin >> a >> b;
		ll ah = lower_bound(v.begin(), v.end(), a) - v.begin();//입력값이 몇 층인지
		ll aw = v[ah] - a;//a가 각 층의 맨 오른쪽에서 얼마나 떨어져 있는지
		ll w = h + 1 - (ah - 1);//몇 개로 분배가 되는지
		ll st = (h + 1) - aw - w + 1;//값을 넣는 시작점
		ll en = (h + 1) - aw;//값이 끝나는 곳

		query_lazy(st, en, 1, 1, n, b / w);
	}

	while (r--) {
		ll a, b;
		cin >> a >> b;
		cout << query(a, b, 1, 1, n) << "\n";
	}
	return 0;
}
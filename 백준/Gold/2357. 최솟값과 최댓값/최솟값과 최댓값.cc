#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

vector <ll> segMin;
vector <ll> segMax;
int h = 1, n, m;

void update(int i, ll val) {
	i += h - 1;
	int a = i, b = i;
	segMin[i] = val;
	while (a > 1) {
		a /= 2;
		segMin[a] = min(segMin[a * 2], segMin[a * 2 + 1]);
	}

	segMax[i] = val;
	while (b > 1) {
		b /= 2;
		segMax[b] = max(segMax[b * 2], segMax[b * 2 + 1]);
	}
}

ll queryMax(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) return segMax[nodeNum];
	else if (nodeR < L || R < nodeL) return -1;
	int mid = (nodeL + nodeR) / 2;
	return max(queryMax(L, R, nodeNum * 2, nodeL, mid), queryMax(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}
ll queryMin(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) return segMin[nodeNum];
	else if (nodeR < L || R < nodeL) return 1e10 + 1;
	int mid = (nodeL + nodeR) / 2;
	return min(queryMin(L, R, nodeNum * 2, nodeL, mid), queryMin(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

int main() {
	FIO;
	cin >> n >> m;
	while (n > h)
		h <<= 1;

	segMin.resize(h * 2);
	fill(segMin.begin(), segMin.end(), INT_MAX);
	segMax.resize(h * 2);
	fill(segMax.begin(), segMax.end(), -1);

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		update(i, x);
	}
	for (int i = 0; i < m; i++) {
		ll b, c;
		cin >> b >> c;
		cout << queryMin(b, c, 1, 1, h) << " ";
		cout << queryMax(b, c, 1, 1, h) << "\n";
	}

	return 0;
}
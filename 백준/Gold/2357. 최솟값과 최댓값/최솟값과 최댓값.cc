#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <string.h>
#include <utility>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

vector<ll>segMin;
vector<ll>segMax;
int h = 1;
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
	else if (nodeR < L || R < nodeL) return 1e10+1;
	int mid = (nodeL + nodeR) / 2;
	return min(queryMin(L, R, nodeNum * 2, nodeL, mid), queryMin(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	while (N > h)h <<= 1;
	segMin.resize(h * 2);
	fill(segMin.begin(),segMin.end(), 1e11);
	segMax.resize(h * 2);
	fill(segMax.begin(), segMax.end(), -1);

	for (int i = 1; i <= N; i++) {
		ll x;
		scanf("%lld", &x);
		update(i, x);
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		ll c;
		scanf("%d %d", &b, &c);
		printf("%lld ", queryMin(b, c, 1, 1, h));
		printf("%lld\n", queryMax(b, c, 1, 1, h));
	}
	return 0;
}
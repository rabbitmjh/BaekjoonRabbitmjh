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

vector<ll>seg;
int h = 1;
void update(int i, ll val) {
	i += h - 1;
	if (val > 0)seg[i] = 1;
	else if (val < 0)seg[i] = -1;
	else seg[i] = 0;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] * seg[i * 2 + 1];
	}
}
ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) return seg[nodeNum];
	else if (nodeR < L || R < nodeL) return 1;
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, nodeNum * 2, nodeL, mid) * query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main() {
	int N, M;
	while (scanf("%d %d", &N, &M) != EOF) {
		while (N > h)h <<= 1;
		seg.clear();
		seg.resize(h * 2);
		for (int i = 1; i <= N; i++) {
			ll x;
			scanf(" %lld", &x);
			update(i, x);
		}
		for (int i = 0; i < M; i++) {
			char a;
			int b, c;

			scanf(" %c %d %d", &a, &b, &c);
			if (a == 'C') {
				update(b, c);
			}
			else {
				ll sum = query(b, c, 1, 1, h);

				if (!sum)printf("0");
				else if (sum > 0)printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}
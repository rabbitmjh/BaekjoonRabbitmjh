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

ll seg[4000005];

ll update(int pos, int val, int nodeNum, int L, int R) {
	if (R < pos || pos < L)
		return seg[nodeNum];
	if (L == R)
		return seg[nodeNum] = val;
	int mid = (L + R) >> 1;
	return seg[nodeNum] = (update(pos, val, nodeNum * 2, L, mid)*update(pos, val, nodeNum * 2 + 1, mid + 1, R)) % 1000000007;
}
ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	//L,R : 세그에서 찾으려는 값의 범위
	//nodeNum : 현재 보고있는노드
	//nodeR,L : 현재 보고있는 범위
	if (nodeR < L || R < nodeL)
		return 1;
	if (L <= nodeL && nodeR <= R)
		return seg[nodeNum];
	
	int mid = (nodeL + nodeR) >> 1;

	return (query(L, R, nodeNum * 2, nodeL, mid) * query(L, R, nodeNum * 2 + 1, mid + 1, nodeR)) % 1000000007;

}
int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);


	for (int i = 1; i <= N; i++) {
		ll x;
		scanf("%lld", &x);
		update(i, x, 1, 1, N);
	}
	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			update(b, c, 1, 1, N);
		}
		else {
			printf("%lld\n", query(b, c, 1, 1, N));
		}
	}
	return 0;
}
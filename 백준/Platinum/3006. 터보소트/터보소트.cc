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

vector <p> seg;
int h = 1, n;
int arr[100005];

void update(int i, ll val) {
	i += h - 1;
	seg[i].first = val;
	seg[i].second = 1;
	while (i > 1) {
		i /= 2;
		seg[i].second = seg[i * 2].second + seg[i * 2 + 1].second;
	}
}

void updateToZero(int i) {
	seg[i].first = 0;
	seg[i].second = 0;
	while (i > 1) {
		i /= 2;
		seg[i].second = seg[i * 2].second + seg[i * 2 + 1].second;
	}
}

ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) return seg[nodeNum].second;
	else if (nodeR < L || R < nodeL) return 0;
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
	scanf("%d", &n);
	while (n > h)h <<= 1;
	seg.resize(h * 2);

	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		arr[x] = i;
		update(i, x);
	}
	int low = 1, high = n;
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			updateToZero(arr[low] + h - 1);
			printf("%d\n", query(1, arr[low] - 1, 1, 1, h));
			low++;
		}
		else {
			updateToZero(arr[high] + h - 1);
			printf("%d\n", query(arr[high] + 1, n, 1, 1, h));
			high--;
		}
	}
	return 0;
}

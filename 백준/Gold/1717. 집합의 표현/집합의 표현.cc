#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
int root[1000005];
int n, m;
int find(int x) {
	if (root[x] == x)return x;
	else return root[x] = find(root[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	root[y] = x;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++)root[i] = i;
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &c, &a, &b);
		if (!c)merge(a, b);
		else {
			if (find(a) == find(b))printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}
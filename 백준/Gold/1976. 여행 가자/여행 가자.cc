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
int parent[205];
int arr[1005];
int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}
void mearge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	parent[y] = x;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			if (a)mearge(i, j);
		}
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i < m; i++) {
		if (find(arr[i]) != find(arr[i - 1])) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
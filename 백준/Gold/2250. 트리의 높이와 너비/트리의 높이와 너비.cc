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
int n, mx, level, ptr, finallevel;
int findRoot[10005];
vector <vector<p>> v(10005);
vector <vector<int>> sum(10005);

void inorder(int root, int level) {
	finallevel = max(level, finallevel);
	if (v[root][0].first != -1)inorder(v[root][0].first, level + 1);
	ptr++;
	sum[level].push_back(ptr);
	if (v[root][0].second != -1)inorder(v[root][0].second, level + 1);
}

int main() {
	cin >> n;
	int a, b, c, d;
	while (n--) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		if (b != -1)findRoot[b] = a;
		if (c != -1)findRoot[c] = a;
		d = a;
	}
	while (findRoot[d]) {
		d = findRoot[d];
	}

	inorder(d, 1);

	for (int i = 1; i <= finallevel; i++) {
		int wide = sum[i][sum[i].size()-1] - sum[i][0];
		if (wide + 1 > mx) {
			mx = wide + 1;
			level = i;
		}
	}
	printf("%d %d", level, mx);
	return 0;
}
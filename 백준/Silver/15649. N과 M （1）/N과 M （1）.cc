#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <string.h>
#include <limits.h>
#include <math.h>
using namespace std;
int n, m;
int arr[9];
vector <int> v;
bool visit[9];

void dfs() {
	if (v.size() == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true; v.push_back(i);
			dfs();
			visit[i] = false; v.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	dfs();

	return 0;
}
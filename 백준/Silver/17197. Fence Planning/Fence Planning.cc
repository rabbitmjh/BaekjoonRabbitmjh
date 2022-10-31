#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
typedef pair <int, p> pp;

int n, m, sum = 1e9;
vector <pp> v;
vector <vector<int>> v1(100005);
int vis[100005];
p arr[100005];

void bfs(int i) {
	int max_x = 0, min_x = 1e9, max_y = 0, min_y = 1e9;
	queue <int> q;
	q.push(i);
	vis[i] = 1;
	while (!q.empty()) {
		int nx = q.front();
		q.pop();
		max_x = max(arr[nx].first, max_x);
		min_x = min(arr[nx].first, min_x);
		max_y = max(arr[nx].second, max_y);
		min_y = min(arr[nx].second, min_y);
		for (int j = 0; j < v1[nx].size(); j++) {
			if (!vis[v1[nx][j]]) {
				q.push(v1[nx][j]);
				vis[v1[nx][j]] = 1;
			}
		}
	}
	sum = min(sum, (max_x - min_x + max_y - min_y) * 2);
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[i].first = x, arr[i].second = y;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])continue;
		else {
			bfs(i);
		}
	}
	printf("%d\n", sum);
	return 0;
}
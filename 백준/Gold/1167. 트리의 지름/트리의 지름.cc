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
int v, sum, ans, rem;
int vis[100005];
vector <vector<p>> tree(100005);//1번째는 이어진 정점 2번째는 그 정점과의 거리
queue <p> q;

void bfs(int node, int len) {
	for (int i = 0; i < tree[node].size(); i++) {
		q.push({ tree[node][i].first,tree[node][i].second });
		vis[tree[node][i].first] = 1;
	}
	while (!q.empty()) {
		int next = q.front().first;
		int len = q.front().second;
		q.pop();
		if (len > sum) {
			sum = len;
			rem = next;
		}
		for (int i = 0; i < tree[next].size(); i++) {
			if (!vis[tree[next][i].first]) {
				q.push({ tree[next][i].first,tree[next][i].second + len });
				vis[tree[next][i].first] = 1;
			}
		}
	}

}

int main() {
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int n, a, b;
		cin >> n;
		while (scanf("%d", &a) && a != -1) {
			scanf("%d", &b);
			tree[n].push_back({ a,b });
		}
	}
	vis[1] = 1;
	bfs(1, 0);
	ans = sum;
	memset(vis, 0, sizeof(vis));

	vis[rem] = 1;
	bfs(rem, 0);
	ans = max(ans, sum);

	printf("%d", ans);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, j, a, b;
int vis[1005];
vector <vector<int>> v(1005);

void dfs(int num) {
	cout << num <<" ";
	vis[num] = 1;
	for (int i = 0; i < v[num].size(); i++) {
		if (vis[v[num][i]] == 0) {
			vis[v[num][i]] = 1;
			dfs(v[num][i]);
		}
	}
}

void bfs(int num) {
	queue <int> q;
	q.push(num);
	while (!q.empty()) {
		int f = q.front();
		vis[f] = 1;
		cout << f << " ";
		q.pop();

		for (int i = 0; i < v[f].size(); i++) {
			if (vis[v[f][i]] == 0) {
				vis[v[f][i]] = 1;
				q.push(v[f][i]);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> j;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());

	dfs(j);
	memset(vis, 0, sizeof(vis));

	cout << endl;
	bfs(j);
	return 0;
}
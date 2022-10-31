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

int n, a, b, vis[3005];
vector <int> v[3005], ring;
bool check, ans[3005];

void dfs(int station, int start, int cnt) {//순환선 찾기
	if (start == station && cnt > 1) {
		ans[start] = true;
		return;
	}
	vis[station] = 1;

	for (int i = 0; i < v[station].size(); i++) {
		int next = v[station][i];
		if (!vis[next])
			dfs(next, start, cnt + 1);
		else if (start == next && cnt > 1)
			dfs(next, start, cnt);
	}
	return;
}

void bfs(int m) {//각 역에서 순환선이 얼마나 떨어져 있는지
	queue <p> q;
	q.push({ m,0 });
	while (!q.empty()) {
		int next = q.front().first;
		int cnt = q.front().second;
		q.pop();
		vis[next] = 1;
		if (ans[next]) {
			cout << cnt << " ";
			return;
		}
		for (int i = 0; i < v[next].size(); i++) {
			if (!vis[v[next][i]])
				q.push({ v[next][i],cnt + 1 });
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, i, 0);
		memset(vis, 0, sizeof(vis));
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
		memset(vis, 0, sizeof(vis));
	}

	return 0;
}
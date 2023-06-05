#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, mn, ans, c[305][305], f[305][305], vis[305];
vector <int> v[305];

void bfs() {
	queue <int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto i : v[now]) {
			if (!vis[i] && c[now][i] > f[now][i]) {
				q.push(i);
				vis[i] = now;
				if (i == n)
					break;
			}
		}
	}
}

void go(int x) {
	if (x == 1) return;
	else go(vis[x]);
	mn = min(mn, c[vis[x]][x] - f[vis[x]][x]);
	return;
}
void goo(int x) {
	if (x == 1) return;
	else goo(vis[x]);
	f[vis[x]][x] += mn;
	f[x][vis[x]] -= mn;
	return;
}

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		c[x][y] += z;
		c[y][x] += z;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		bfs();
		if (!vis[n])
			break;

		mn = INT_MAX;

		go(n);
		goo(n);
		ans += mn;

		memset(vis, 0, sizeof(vis));
	}

	cout << ans;

	return 0;
}
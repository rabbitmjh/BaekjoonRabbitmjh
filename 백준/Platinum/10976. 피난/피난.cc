#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, n, m, ans, mn;
int c[205][205], f[205][205], vis[205];
vector <int> v[205];

void go(int x) {
	if (x == 1) return;
	else go(vis[x]);
	mn = min(mn, c[vis[x]][x] - f[vis[x]][x]);
	return;
}
void goo(int x) {
	if (x == 1) return;
	else goo(vis[x]);
	c[vis[x]][x] -= mn;
	c[x][vis[x]] += mn;
	return;
}

void bfs() {
	memset(vis, -1, sizeof(vis));
	queue <int> q;
	q.push(1);
	vis[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto i : v[now]) {
			if (c[now][i] - f[now][i] > 0 && vis[i] == -1) {
				q.push(i);
				vis[i] = now;
				if (i == n)
					break;
			}
		}
	}
	return;
}



int main() {
	FIO;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			if (x == 1 || y == n)
				c[x][y] = 1;
			else
				c[x][y] = INT_MAX;
			v[x].push_back(y);
			v[y].push_back(x);
		}

		for (int i = 1; i <= n; i++) {
			bfs();
			if (vis[n] == -1)
				break;
			mn = INT_MAX;
			go(n);
			goo(n);
			ans += mn;

			memset(vis, -1, sizeof(vis));
		}

		cout << ans << "\n";
		for (int i = 1; i <= n; i++)
			v[i].clear();
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		ans = 0;
		mn = INT_MAX;
	}

	return 0;
}
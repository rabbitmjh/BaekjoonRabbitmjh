#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans;
int c[205][205], f[205][205], vis[205];
vector <int> v[205];

void bfs() {
	while (1) {
		memset(vis, -1, sizeof(vis));
		queue <int> q;
		q.push(200);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (auto i : v[now]) {
				if (c[now][i] - f[now][i] > 0 && vis[i] == -1) {
					q.push(i);
					vis[i] = now;
					if (i == 201)
						break;
				}
			}
		}
		if (vis[201] == -1)
			break;

		int mn = INT_MAX;
		for (int i = 201; i != 200; i = vis[i])
			mn = min(mn, c[vis[i]][i] - f[vis[i]][i]);
		for (int i = 201; i != 200; i = vis[i]) {
			f[vis[i]][i] += mn;
			f[i][vis[i]] -= mn;
		}
		ans += mn;
	}
	return;
}



int main() {
	FIO;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> c[200][i];
		v[200].push_back(i);
		v[i].push_back(200);
	}
	for (int i = 0; i < m; i++) {
		cin >> c[100 + i][201];
		v[100 + i].push_back(201);
		v[201].push_back(100 + i);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[j][100 + i];
			v[100 + i].push_back(j);
			v[j].push_back(100 + i);
		}
	}

	bfs();

	cout << ans;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, n, m, ans, vis[30005], man[30005];
vector <int> v[30005];

int dfs(int cur, int parent, bool root, int now) {
	vis[cur] = now;
	int tmp = vis[cur];
	int cnt = 0;

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (parent == next)
			continue;

		if (vis[next]) {
			tmp = min(tmp, vis[next]);
			continue;
		}

		cnt++;
		int ne = dfs(next, cur, false, now + 1);
		if (!root && (vis[cur] <= ne))
			man[cur] = 1;
		
		tmp = min(tmp, ne);
	}

	if (root && (cnt > 1))
		man[cur] = 1;

	return tmp;
}

int main() {
	FIO;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= n; i++)
			sort(v[i].begin(), v[i].end());

		for (int i = 1; i <= n; i++) {
			if (!vis[i])
				dfs(i, 0, true, 1);
		}

		for (int i = 1; i <= n; i++)
			if (man[i])
				ans++;

		if (!ans)cout << "NO\n";
		else cout << "YES\n";

		ans = 0;
		for (int i = 1; i <= n; i++)
			v[i].clear();
		memset(vis, 0, sizeof(vis));
		memset(man, 0, sizeof(man));
	}
	

	return 0;
}
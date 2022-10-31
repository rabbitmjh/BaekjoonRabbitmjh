#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, num, sum, vis[100005];
vector <int> v[100005];
vector <p> ans;

int dfs(int cur, int parent) {
	vis[cur] = ++num;
	int ret = vis[cur];

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (next == parent)continue;
		if (vis[next]) {
			ret = min(ret, vis[next]);
			continue;
		}

		int pre = dfs(next, cur);

		if (pre > vis[cur])
			ans.push_back({ min(cur, next),max(cur, next) });
		ret = min(ret, pre);
	}

	return ret;
}

int main() {
	FIO;
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, 0);
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << "\n";

	return 0;
}
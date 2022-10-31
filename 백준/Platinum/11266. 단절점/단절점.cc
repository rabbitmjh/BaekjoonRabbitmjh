#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, num, sum, vis[100005], ans[100005];
vector <int> v[100005];

int dfs(int cur, bool root) {
	vis[cur] = ++num;
	int ret = vis[cur];
	int child = 0;
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i];
		if (vis[next]) {
			ret = min(ret, vis[next]);
			continue;
		}
		child++;
		int pre = dfs(next, false);

		if (!root && pre >= vis[cur])
			ans[cur] = 1;
		ret = min(ret, pre);
	}
	if (root && child > 1)
		ans[cur] = 1;
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
	
	for (int i = 1;i <= n;i++)
		if (!vis[i])
			dfs(i, true);
	for (int i = 1;i <= n;i++)
		if (ans[i])
			sum++;

	cout << sum << "\n";
	for (int i = 1;i <= n;i++)
		if (ans[i])
			cout << i << " ";

	return 0;
}
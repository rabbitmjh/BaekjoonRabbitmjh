#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, depth[50005], parent[50005], check[50005];
vector <int> v[50005];
vector<int> ans;

void dfs(int cur, int level) {
	check[cur] = 1;
	depth[cur] = level;
	for (int i = 0; i < v[cur].size(); i++) {
		if (!check[v[cur][i]]) {
			parent[v[cur][i]] = cur;
			dfs(v[cur][i], level + 1);
		}
	}
	return;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (depth[a] > depth[b])
			swap(a, b);

		while (depth[a] != depth[b])
			b = parent[b];

		while (a != b) {
			a = parent[a];
			b = parent[b];
		}
		ans.push_back(a);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}
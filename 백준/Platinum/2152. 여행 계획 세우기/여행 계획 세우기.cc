#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> pp;

int n, m, s, k, p[10005], scc[10005], dist[10005];
bool vis[10005];
vector <vector<int>> adj, adj2, scc_adj;
stack <int> st;

void dfs(int v) {
	vis[v] = true;
	for (int i : adj[v]) {
		if (vis[i]) continue;
		dfs(i);
	}
	st.push(v);
}
void rdfs(int v, int t) {
	vis[v] = true;
	p[v] = t;
	scc[t]++;
	for (int i : adj2[v]) {
		if (vis[i]) {
			if (p[i] != p[v]) {
				scc_adj[p[i]].push_back(p[v]); 
			}
			continue;
		}
		else rdfs(i,t);
	}
}

int main() {
	cin >> n >> m >> s >> k;
	adj.resize(n + 1);
	adj2.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int q, w;
		cin >> q >> w;
		adj[q].push_back(w);
		adj2[w].push_back(q);
	}
	
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}
	memset(vis, false, sizeof(vis));

	int tmp = 0;
	while (!st.empty()) {
		int cur = st.top();
		st.pop();

		if (vis[cur]) continue;
		scc_adj.resize(++tmp);
		rdfs(cur, tmp - 1);
	}
	if (p[s] == p[k]) {
		cout << scc[p[s]] << '\n';
	}
	else {
		dist[p[s]] = scc[p[s]];
		queue<int> q;
		q.push(p[s]);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == p[k]) continue;
			for (int i : scc_adj[cur]) {
				if (dist[i] < dist[cur] + scc[i]) {
					dist[i] = dist[cur] + scc[i];
					q.push(i);
				}
			}
		}
		cout << dist[p[k]] << '\n';
	}

	return 0;
}
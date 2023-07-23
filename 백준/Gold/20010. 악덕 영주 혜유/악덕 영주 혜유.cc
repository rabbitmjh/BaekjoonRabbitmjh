#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<ll, p> pp;

int V, E, u, v;
ll w;
ll res = 0, M = 0;

struct Edge {
	ll cost;
	int node[2];
	Edge(int u, int v, ll cost) {
		this->cost = cost;
		this->node[0] = u;
		this->node[1] = v;
	}
	bool operator<(Edge e) {
		return this->cost < e.cost;
	}
};

vector <Edge> edges;
vector <int> Parent, Rank;
vector <bool> chk;
vector<pair<int, ll>> tree[1000];

int findParent(int u) {
	if (Parent[u] == u) return u;
	return Parent[u] = findParent(Parent[u]);
}

void mergeParent(int u, int v) {
	u = findParent(u);
	v = findParent(v);
	if (u == v)return;
	if (Rank[u] > Rank[v]) swap(u, v);
	Parent[u] = v;
	if (Rank[u] == Rank[v]) Rank[v]++;
}

void dfs(int k, ll w = 0) {
	M = max(M, w);
	for (int i = 0; i < tree[k].size(); i++) {
		if (chk[tree[k][i].first] == false) {
			chk[tree[k][i].first] = true;
			dfs(tree[k][i].first, w + tree[k][i].second);
			chk[tree[k][i].first] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	Rank.resize(V, 1);
	Parent.resize(V);

	for (int i = 0; i < V; i++)Parent[i] = i;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edges.push_back(Edge(u, v, w));
	}

	sort(edges.begin(),edges.end());

	for (int i = 0; i < (int)edges.size(); i++) {
		ll cost = edges[i].cost;
		int L = edges[i].node[0];
		int R = edges[i].node[1];
		if (findParent(L) == findParent(R))continue;
		mergeParent(L, R);
		tree[L].push_back({ R, cost });
		tree[R].push_back({ L, cost });
		res += cost;
	}

	for (int i = 0; i < V; i++) {
		chk.clear();
		chk.resize(V);
		chk[i] = true;
		dfs(i);
	}
	cout << res << '\n' << M;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, a, b, t, vis[20005], ans;
vector <vector<p>> city(20005);
priority_queue<pp, vector<pp>, greater<pp>> pq;

void go() {
	while (!pq.empty()) {
		int cost = pq.top().first;
		int next = pq.top().second.first;
		int parent = pq.top().second.second;
		pq.pop();

		if (vis[next] && vis[parent])
			continue;

		if ((next == a && parent == b) || (next == b && parent == a))
			ans = 1;

		vis[next] = 1;
		vis[parent] = 1;
	}
}

int main() {
	FIO;
	cin >> t;
	while (t--) {
		cin >> n >> m >> a >> b;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			pq.push({ w,{u,v} });
			pq.push({ w,{v,u} });
		}
		go();

		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
		ans = 0;
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}
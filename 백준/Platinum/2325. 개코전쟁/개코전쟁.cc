#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <limits.h>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<vector<p>>v;
stack<pair<int,int>>s;
ll path[1001];
ll dist[1001];
ll n, m;
ll ans = 0;
void dijkstra(ll ds, ll de) {
	priority_queue<p, vector<p>, greater<p>>pq;
	fill(dist, dist + 1001, LLONG_MAX);
	dist[1] = 0;
	for (int i = 1; i <= n; i++) pq.push({ dist[i],i });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dist[cur.second] < cur.first) continue;
		for (int i = 0; i < v[cur.second].size(); i++) {
			ll npos = v[cur.second][i].first;
			if ((cur.second== ds && npos == de) || (cur.second == de && npos == ds))continue;
			ll ncost = v[cur.second][i].second;
			if (dist[npos] > dist[cur.second] + ncost) {
				dist[npos] = dist[cur.second] + ncost;
				pq.push({ dist[npos],npos });
				path[npos] = cur.second;
			}
		}
	}
	if (dist[n] != LLONG_MAX) ans = max(ans, dist[n]);
	else return;
}
int main() {
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		ll a, b;
		ll c;
		scanf("%lld %lld %lld", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijkstra(0,0);

	int c = n;
	while (1) {
		s.push({c,path[c]});
		if (path[c] == 1)break;
		c = path[c];
	}

	while (!s.empty()) {
		auto p = s.top();
		s.pop();
		dijkstra(p.first,p.second);
	}
	printf("%lld", ans);
	return 0;
}
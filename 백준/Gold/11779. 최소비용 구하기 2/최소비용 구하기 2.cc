#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e10;
const int MAX_V = 1005;

int arr[1005];
int n, m, t;

int main() {
	scanf("%d %d", &n, &m);
	vector<P>adj[MAX_V];
	for (int i = 0; i < m; i++) {
		int v, w, cost;
		scanf("%d %d %d", &v, &w, &cost);
		adj[v].push_back(P(w, cost));
	}
	int from, to;
	scanf("%d %d", &from, &to);
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	bool visited[MAX_V] = { 0 };
	priority_queue<P, vector<P>, greater<P>>pq;
	dist[from] = 0;
	pq.push({ 0,from });
	while (!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curr]);
		if (visited[curr])break;
		visited[curr] = true;

		for (int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i].first, d = adj[curr][i].second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				arr[next] = curr;
  				pq.push({ dist[next],next });
			}
		}
	}

	vector <int> v;
	v.push_back(to);
	int i = 0,a=1e10;
	while (a!=from) {
		a = arr[v[i]];
		v.push_back(a);
		i++;
	}
	printf("%d\n", dist[to]);
	printf("%d\n", v.size());
	for (int i = v.size()-1; i >-1; i--) {
		printf("%d ", v[i]);
	}
	return 0;
}

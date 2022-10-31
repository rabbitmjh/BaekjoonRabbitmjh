#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int INF = 1e10;
const int MAX_V = 1005;

int arr[1005];
int n, m, t, x;

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &x);
	vector<P>adj[MAX_V];
	vector<int>v;
	for (int i = 0; i < m; i++) {
		int v, w, cost;
		scanf("%d %d %d", &v, &w, &cost);
		adj[v].push_back(P(w, cost));
	}
	for (int i = 1; i <= n; i++) {
		int dist[MAX_V];
		fill(dist, dist + MAX_V, INF);
		bool visited[MAX_V] = { 0 };
		priority_queue<P, vector<P>, greater<P>>pq;
		dist[i] = 0;
		pq.push({ 0,i });
		while (!pq.empty()) {
			int curr;
			do {
				curr = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visited[curr]);
			if (visited[curr])break;
			visited[curr] = true;
			for (int k = 0; k < adj[curr].size(); k++) {
				int next = adj[curr][k].first, d = adj[curr][k].second;
				if (dist[next] > dist[curr] + d) {
					dist[next] = dist[curr] + d;
					pq.push({ dist[next],next });
				}
			}
		}
		if (x == i) {
			for (int j = 1; j <= n; j++) {
				if (j == x)continue;
				arr[j] += dist[j];
			}
		}
		else arr[i] += dist[x];
	}

	sort(arr,arr+n+1);
	printf("%d", arr[n]);
	return 0;
}

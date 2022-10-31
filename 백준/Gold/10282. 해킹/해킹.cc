#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
const int INF = 1e10;

int n, d, c, t, a, b, s;

int main() {
	cin >> t;
	while (t--) {
		int sum = 0, time = 0;
		vector <p> v[10005];
		vector <int> ans;
		scanf("%d%d%d", &n, &d, &c);
		for (int i = 0; i < d; i++) {
			scanf("%d%d%d", &a, &b, &s);
			v[b].push_back({ a,s });
		}

		int dist[10005];
		fill(dist, dist + 10005, INF);
		bool vis[10005] = { 0 };
		priority_queue<p, vector<p>, greater<p>> pq;
		dist[c] = 0;

		pq.push({ 0,c });
		while (!pq.empty()) {
			int curr;
			do {
				curr = pq.top().second;
				pq.pop();
			} while (!pq.empty() && vis[curr]);
			if (vis[curr])break;
			vis[curr] = true;
			for (int j = 0; j < v[curr].size(); j++) {
				int next = v[curr][j].first;
				int d = v[curr][j].second;

				if (dist[next] > dist[curr] + d) {
					dist[next] = dist[curr] + d;
					pq.push({ dist[next], next });
				}

			}
		}
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				sum++;
				if (dist[i] > time)time = dist[i];
			}
		}
		cout << sum << " " << time << endl;
	}
	return 0;
}
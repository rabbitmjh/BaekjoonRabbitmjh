#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<string, p> pp;

vector <vector<p>> V(10005);
int mac[10005], sta[10005], time[10005];
int dij1[10005], dij2[10005];
priority_queue<p, vector<p>, greater<p>> pq;

void dij(int arr[]) {
	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (arr[now] < cost)continue;
		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i].first;
			int Ncost = V[now][i].second;
			int sum = cost + Ncost;

			if (arr[next] > sum) {
				arr[next] = sum;
				pq.push({ sum,next });
			}
		}
	}
}
int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}

	int mc, x;
	cin >> mc >> x;
	for (int i = 0; i < mc; i++) {
		scanf("%d", &mac[i]);
		time[mac[i]] = 1;
	}

	int st, y;
	cin >> st >> y;
	for (int i = 0; i < st; i++) {
		scanf("%d", &sta[i]);
		time[sta[i]] = 1;
	}

	fill(dij1, dij1 + 10005, 2e9);
	fill(dij2, dij2 + 10005, 2e9);

	for (int i = 0; i < mc; i++) {
		dij1[mac[i]] = 0;
		pq.push({ 0,mac[i] });
	}
	dij(dij1);
	for (int i = 0; i < st; i++) {
		dij2[sta[i]] = 0;
		pq.push({ 0,sta[i] });
	}
	dij(dij2);

	int ans = 2e9;
	for (int i = 1; i <= v; i++) {
		if (dij1[i] > x || dij2[i] > y || time[i] == 1)continue;
		ans = min(ans, dij1[i] + dij2[i]);
	}
	if (ans >= 2e9)printf("-1");
	else printf("%d", ans);
	return 0;
}
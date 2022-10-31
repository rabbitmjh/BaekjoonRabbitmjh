#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
int n, m, sum;
vector <vector<p>> v(10005);
priority_queue<p, vector<p>, greater<p>> pq;
bool vis[10005];

void st(int a) {
	pq.push({ 0,a });
	while (!pq.empty()) {
		int next = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (vis[next]) continue;
		vis[next] = true;
		sum += cost;
		for (int i = 0; i < v[next].size(); i++) {
			pq.push({ v[next][i].second,v[next][i].first });
		}
	}
}

int main() {
	int a, b, c;
	cin >> n >> m;
	while (m--) {

		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	st(a);
	printf("%d", sum);
	return 0;
}
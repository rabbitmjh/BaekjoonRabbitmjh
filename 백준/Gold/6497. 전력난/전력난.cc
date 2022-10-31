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
bool vis[10005];

void st(int a) {
	priority_queue<p, vector<p>, greater<p>> pq;
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
	while (scanf("%d %d", &m, &n) && m != 0 && n != 0) {
		int x, y, z, sumOfz = 0;
		while (n--) {
			scanf("%d %d %d", &x, &y, &z);
			v[x].push_back({ y,z });
			v[y].push_back({ x,z });
			sumOfz += z;
		}
		st(x);
		printf("%d\n", sumOfz - sum);

		v.clear();
		v.resize(10005);
		sum = 0;
		memset(vis, false, sizeof(vis));
	}
	return 0;
}
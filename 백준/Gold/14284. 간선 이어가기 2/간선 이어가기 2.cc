#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <climits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, a, b, c, s, t, ans, arr[5005], INF = INT_MAX;
vector <p> v[5005];
priority_queue <p> pq;

void dij(int s) {
	pq.push({ s,0 });
	while (!pq.empty()) {
		int next = pq.top().first;
		int node = -pq.top().second;
		pq.pop();
		if (arr[next] < node)continue;

		for (int i = 0; i < v[next].size(); i++) {
			int a = v[next][i].first;
			int b = v[next][i].second + node;
			if (arr[a] > b) {
				pq.push({ a, -b });
				arr[a] = b;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	fill(arr, arr + n + 1, INF);
	cin >> s >> t;
	arr[s] = 0;
	dij(s);

	cout << arr[t];

	return 0;
}
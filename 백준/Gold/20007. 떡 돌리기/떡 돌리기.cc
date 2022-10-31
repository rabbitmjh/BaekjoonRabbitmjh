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

int n, m, a, b, c, x, y, ans = 1, arr[1005], INF = INT_MAX;
vector <p> v[1005];
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

	cin >> n >> m >> x >> y;
	while (m--) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	fill(arr, arr + n, INF);
	arr[y] = 0;
	dij(y);

	sort(arr, arr + n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] * 2 > x) {
			cout << "-1";
			return 0;
		}
		if (sum + arr[i] * 2 <= x)
			sum += arr[i] * 2;
		else {
			sum = arr[i] * 2;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
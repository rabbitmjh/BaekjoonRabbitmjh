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
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

ll n, m, a, b, t, w, arr[20005], INF = INT_MAX;
vector <pp> v[20005];
priority_queue <p> pq;

void dij(int s) {
	pq.push({ 0,s });

	while (!pq.empty()) {
		ll time = -pq.top().first;
		ll cur = pq.top().second;
		pq.pop();

		if (arr[cur] < time)continue;
		//역 대기시간을 나머지로 더해준다
		for (int i = 0; i < v[cur].size(); i++) {
			ll nextTime = v[cur][i].first;
			ll next = v[cur][i].second.first;
			ll nextTrain = v[cur][i].second.second;

			if (time % nextTrain == 0 && arr[next] > time + nextTime) {
				arr[next] = time + nextTime;
				pq.push({ -arr[next],next });
			}
			else {
				ll num = 0;
				for (int j = 0; j < 10; j++) {
					if ((time + j) % nextTrain == 0) {
						num = time + j;
						break;
					}
				}
				if (arr[next] > num + nextTime) {
					arr[next] = num + nextTime;
					pq.push({ -arr[next],next });
				}
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
		cin >> a >> b >> t >> w;
		v[a].push_back({ t,{b,w} });
	}

	fill(arr, arr + n + 1, INF);
	arr[1] = 0;
	dij(1);
	cout << arr[n];

	return 0;
}
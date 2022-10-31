#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, st, mn = INT_MAX, ans, arr[100005], vis[100005];
vector <p> v[100005];
priority_queue <p, vector<p>, greater<p>> pq;

int find(int num) {
	if (arr[num] < 0) return num;
	return arr[num] = find(arr[num]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b)return;
	arr[a] += arr[b];
	arr[b] = a;
}

void go() {
	while (!pq.empty()) {
		int dis = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (vis[cur])
			continue;
		vis[cur] = 1;
		ans += dis;
		for (int i = 0; i < v[cur].size(); i++) {
			int nd = v[cur][i].first;
			int nc = v[cur][i].second;

			if (vis[nc])
				continue;
			pq.push({ nd, nc });
		}
	}

}

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] < mn) {
			mn = arr[i];
			st = i;
		}
	}
	ans += mn;

	while (m--) {
		int s, e, l; cin >> s >> e >> l;
		v[s].push_back({ arr[s] + arr[e] + 2 * l,e });
		v[e].push_back({ arr[s] + arr[e] + 2 * l,s });
	}

	for (int i = 0; i < v[st].size(); i++)
		pq.push({ v[st][i].first,v[st][i].second });
	vis[st] = 1;

	go();
	cout << ans;

	return 0;
}
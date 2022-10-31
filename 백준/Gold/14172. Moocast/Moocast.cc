#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<p, int> pp;

int n, ans, vis[205];
pp cow[205];

int dfs(int m) {
	vis[m] = 1;
	int x = cow[m].first.first;
	int y = cow[m].first.second;
	int r = cow[m].second * cow[m].second;
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		int dis = pow(x - cow[i].first.first, 2) + pow(y - cow[i].first.second, 2);
		if (!vis[i] && dis <= r)
			cnt += dfs(i);
	}

	return cnt;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cow[i].first.first >> cow[i].first.second >> cow[i].second;

	for (int i = 0; i < n; i++) {
		ans = max(dfs(i), ans);
		memset(vis, 0, sizeof(vis));
	}

	cout << ans;
	return 0;
}
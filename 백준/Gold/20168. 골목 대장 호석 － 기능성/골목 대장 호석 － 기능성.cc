#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, a, b, c, ans = INT_MAX, vis[15];
vector <p> v[15];

void go(int cur, int cnt, int maxC) {
	if (cur == b) {
		ans = min(ans, maxC);
		return;
	}
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i].first;
		int nextC = v[cur][i].second;
		if (!vis[next] && cnt + nextC <= c) {
			vis[next] = 1;
			go(next, cnt + nextC, max(maxC, nextC));
			vis[next] = 0;
		}
	}
	return;
}

int main() {
	FIO;
	cin >> n >> m >> a >> b >> c;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z ;
		v[x].push_back({ y,z });
	}

	vis[a] = 1;
	go(a, 0, 0);

	if (ans == INT_MAX)
		cout << -1;
	else cout << ans;

	return 0;
}
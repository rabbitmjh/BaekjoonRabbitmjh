#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, q, water, nowater, ans[100005], vis[100005];
vector <int> v, abc[100005];

void bfs(int num) {
	queue <int> q;
	q.push(num);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (vis[cur])continue;
		vis[cur]++;
		if (v[cur])water++;
		else nowater++;
		
		for (int i = 0; i < abc[cur].size(); i++) {
			int next = abc[cur][i];
			if (!vis[next])
				q.push(next);
		}
	}
	if (water > nowater) {
		q.push(num);
		while (!q.empty()) {
			int cur = q.front();
			vis[cur]++;
			ans[cur] = 1;
			q.pop();
			for (int i = 0; i < abc[cur].size(); i++) {
				int next = abc[cur][i];
				if (vis[next] == 1)
					q.push(next);
			}
		}
	}
}

int main() {
	FIO;
	cin >> n >> m >> q;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		abc[a].push_back(b);
		abc[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			bfs(i);
			water = 0;
			nowater = 0;
		}
	}
	for (int i = 0; i < q; i++) {
		int a; cin >> a;
		cout << ans[a] << "\n";
	}

	return 0;
}
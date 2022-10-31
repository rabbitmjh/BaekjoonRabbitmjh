#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

queue <p> q;
int n, a, m, st, en, vis[200005];
vector <int> v[200005];

void bfs() {
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0;i < v[now].size();i++) {
			int next = v[now][i];
			if (vis[next] > -1)
				continue;
			if (next > 100000) {
				q.push({ next,cnt + 1 });
				vis[next] = cnt + 1;
			}
			else if (next == en) {
				cout << cnt;
				return;
			}
			else {
				q.push({ next,cnt });
				vis[next] = cnt;
			}
		}
	}
	cout << -1;
	return;
}

int main() {
	FIO;
	cin >> n >> m;
	fill(vis, vis + 200005, -1);
	for (int i = 1;i <= m;i++) {
		while (cin >> a && a != -1) {
			v[a].push_back(i + 100000);
			v[i+100000].push_back(a);
		}
	}
	cin >> st >> en;
	q.push({ st, -1 });
	bfs();

	return 0;
}
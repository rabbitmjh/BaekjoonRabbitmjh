#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<double, double> p;
typedef pair<int, p> pp;

int n, m, s, vis[100005];
vector <int> v[100005];
queue <int> q;

bool bfs() {
	q.push(1);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (vis[now])continue;
		vis[now] = 1;
		
		if(!v[now].size())
			return true;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!vis[next])
				q.push(next);
		}
	}
	return false;
}

int main() {
	FIO;
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	cin >> s;
	while (s--) {
		int a; cin >> a;
		vis[a] = 1;
	}
	if (bfs())cout << "yes";
	else cout << "Yes";

	return 0;
}
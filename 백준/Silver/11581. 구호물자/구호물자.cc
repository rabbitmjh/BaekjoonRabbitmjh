#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, vis[105];
vector <int> v[105];
bool c = false;
void dfs(int a) {
	if (vis[a] == -1) {
		c = true;
		return;
	}
	vis[a] = -1;
	for (int i = 0; i < v[a].size(); i++) {
		int next = v[a][i];
		if (vis[next] != 1)
			dfs(next);
		if (c)return;
	}
	vis[a] = 1;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			v[i].push_back(b);
		}
	}

	dfs(1);

	if (c) cout << "CYCLE";
	else cout << "NO CYCLE";

	return 0;
}
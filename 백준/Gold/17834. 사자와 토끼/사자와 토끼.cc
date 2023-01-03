#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

bool check = true;
int n, m, arr[1000005], vis[1000005], lion, rabbit;
vector <int> v[1000005];

void dfs(ll cur) {
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (!vis[next]) {
			vis[next] = 3 - vis[cur];
			if (vis[next] == 1)lion++;
			else rabbit++;
			dfs(next);
		}
		else if (vis[cur] == vis[next]) {
			check = false;
			return;
		}
	}
}

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		lion++;
		vis[i] = 1;
		dfs(i);
	}

	if (!check) cout << "0" << endl;
	else cout << 2 * lion * rabbit << endl;
	return 0;
}
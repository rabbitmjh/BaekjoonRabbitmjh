#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int n, m, r, vis[100005], cnt = 1;
vector <int> v[100005];

void dfs(int next) {
	for (int i = 0;i < v[next].size();i++) {
		if (!vis[v[next][i]]) {
			cnt++;
			vis[v[next][i]] = cnt;
			dfs(v[next][i]);
		}
	}
	return;
}

int main() {

	cin >> n >> m >> r;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1;i <= n;i++) {
		sort(v[i].begin(), v[i].end(), greater<>());
	}
	vis[r] = cnt;
	dfs(r);
	for (int i = 1;i <= n;i++) {
		cout << vis[i] << "\n";
	}
	return 0;
}
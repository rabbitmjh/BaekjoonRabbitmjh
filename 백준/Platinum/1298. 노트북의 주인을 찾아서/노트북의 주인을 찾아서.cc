#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <stack>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans, barn[5005];
vector <int> v[105];
bool vis[5005];

bool dfs(int cow) {
	if (vis[cow])
		return false;
	vis[cow] = true;

	for (int i = 0; i < v[cow].size(); i++) {
		int next = v[cow][i];
		if (!barn[next] || dfs(barn[next])) {
			barn[next] = cow;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		fill(vis, vis + 5005, false);
		if (dfs(i))
			ans++;
	}

	cout << ans;
	return 0;
}
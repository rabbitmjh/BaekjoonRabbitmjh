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

int n, m, ans, a, b, task[1005];
vector <int> v[1005];
bool vis[1005];

bool dfs(int employee) {
	for (int i = 0; i < v[employee].size(); i++) {
		int next = v[employee][i];

		if (vis[next])
			continue;
		vis[next] = true;

		if (!task[next] || dfs(task[next])) {
			task[next] = employee;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		while (a--) {
			cin >> b;
			v[i].push_back(b);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			fill(vis, vis + 1005, false);
			if (dfs(i))
				ans++;
		}
	}

	cout << ans;
	return 0;
}
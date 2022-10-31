#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int f[405][405], c[405][405];
vector <vector<int>>v;
int n, m, s = 1, e = 2, ans;

void dfs() {
	while (1) {
		queue <int> q;
		q.push(s);
		vector <int> v2(n + 1, -1);
		int mf = 2000000000;

		while (!q.empty()) {
			int num = q.front();
			q.pop();

			for (auto next : v[num]) {
				if (c[num][next] - f[num][next] > 0 && v2[next] == -1) {
					q.push(next);
					v2[next] = num;
					if (next == e)
						break;
				}
			}
		}

		if (v2[e] == -1)break;

		for (int i = e; i != s; i = v2[i])
			mf = min(mf, c[v2[i]][i] - f[v2[i]][i]);

		for (int i = e; i != s; i = v2[i]) {
			f[v2[i]][i] += mf;
			f[i][v2[i]] -= mf;
		}
		ans += mf;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);//역방향 추가!
		c[a][b] = 1;
	}

	dfs();

	cout << ans;
	return 0;
}

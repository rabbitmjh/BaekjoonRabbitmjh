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

int f[805][805], c[805][805];
vector <int> v[805];
int n, m, s = 401, e = 2, ans;

void dfs() {
	while (1) {
		int cmp[805], mf = 2000000000;
		fill(cmp, cmp + 805, -1);

		queue <int> q;
		q.push(s);
		cmp[s] = s;

		while (!q.empty()) {
			int num = q.front();
			q.pop();

			for (int i = 0; i < v[num].size(); ++i) {
				int next = v[num][i];
				if (c[num][next] - f[num][next] > 0 && cmp[next] == -1) {
					cmp[next] = num;
					q.push(next);
					if (next == e)break;
				}
			}
		}

		if (cmp[e] == -1)break;

		for (int i = e; i != s; i = cmp[i])
			mf = min(mf, c[cmp[i]][i] - f[cmp[i]][i]);

		for (int i = e; i != s; i = cmp[i]) {
			f[cmp[i]][i] += mf;
			f[i][cmp[i]] -= mf;
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

	for (int i = 1; i <= n; i++) {
		v[i].push_back(i + 400);
		v[i + 400].push_back(i);
		c[i][i + 400] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		//인아웃구분 잘해야됨
		v[a + 400].push_back(b);
		v[b].push_back(a + 400);//역방향 추가1
		v[b + 400].push_back(a);
		v[a].push_back(b + 400);//역방향 추가2

		c[a + 400][b] = 1;
		c[b + 400][a] = 1;
	}

	dfs();

	cout << ans;
	return 0;
}

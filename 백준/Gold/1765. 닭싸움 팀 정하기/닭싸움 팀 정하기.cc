#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans, vis[1005];
vector <p> v[1005];

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char a; int b, c;
		cin >> a >> b >> c;

		v[b].push_back({ a - 'A',c});
		v[c].push_back({ a - 'A',b});
	}
	
	for (int i = 1; i <= n; i++) {
		if (vis[i] != 1)
			ans++;

		vis[i] = 1;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j].first + 'A' == 'F')
				vis[v[i][j].second] = 1;
			else {
				for (int k = 0; k < v[v[i][j].second].size(); k++) {
					if (v[v[i][j].second][k].first + 'A' == 'E')
						vis[v[v[i][j].second][k].second] = 1;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, depth[100005], parent[100005][18];
vector <int> v[100005];

void dfs(int cur, int level) {
	depth[cur] = level;
	for (int i = 0; i < v[cur].size(); i++) {
		if (depth[v[cur][i]] == -1) {
			parent[v[cur][i]][0] = cur;
			dfs(v[cur][i], level + 1);
		}
	}
	return;
}



int main() {
	FIO;
	memset(depth, -1, sizeof(depth));

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1, 0);

	for (int i = 1; i < 17; i++)
		for (int j = 1; j <= n; j++)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (depth[a] > depth[b])
			swap(a, b);

		int diff = depth[b] - depth[a];

		for (int j = 0; diff != 0; j++) {
			if (diff & 1)
				b = parent[b][j];
			diff >>= 1;
		}

		if (a != b) {
			for (int j = 16; j >= 0; j--) {
				if (parent[a][j] != parent[b][j]) {
					a = parent[a][j];
					b = parent[b][j];
				}
			}
			a = parent[a][0];
		}

		cout << a << "\n";
	}

	return 0;
}
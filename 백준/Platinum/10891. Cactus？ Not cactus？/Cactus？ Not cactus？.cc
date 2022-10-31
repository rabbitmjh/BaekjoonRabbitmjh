#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans, vis[100005], arr[100005];
vector <int> v[100005];

int dfs(int cur, int parent) {
	int ret = 0, num = 0;

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (parent != next) {
			if (!vis[next]) {
				vis[next] = vis[cur] + 1;
				ret += dfs(next, cur);
			}
			else if (vis[cur] > vis[next])
				ret++;
			else if (vis[cur] < vis[next])
				num--;
		}
	}
	arr[cur] = ret;

	if (arr[cur] >= 2)
		ans = 1;

	return (ret + num);
}

int main() {
	FIO;
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vis[1] = 1;
	dfs(1, 0);

	if (ans)
		cout << "Not cactus" << endl;
	else
		cout << "Cactus" << endl;
	

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, ans;
vector <p> v[10005];

void dfs(int cur, int num, int b) {
	ans = max(ans, num);
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i].first;
		int w = v[cur][i].second;
		if (b != next) {
			dfs(next, num + w, cur);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, 0, i);
	}
	cout << ans;
	return 0;
}
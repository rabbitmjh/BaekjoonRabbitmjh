#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, s, start, vis[328005];
vector <vector<int>> v;
vector <int> ans;

void ice(int st, int cnt) {
	vis[st] = 1;
	if (st <= s) {
		ans.push_back(cnt);
		return;
	}

	for (int i = 0; i < v[st].size(); i++) {
		int next = v[st][i];
		if (!vis[next])
			ice(next, cnt + 1);
	}
	return;
}


int main() {
	FIO;

	cin >> n >> s >> start;
	v.resize(n + 5);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vis[start] = 1;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (next <= s) {
			ans.push_back(1);
			continue;
		}
		ice(next, 1);
	}

	sort(ans.begin(), ans.end());

	cout << n - ans[0] - ans[1] - 1 << endl;

	return 0;
}
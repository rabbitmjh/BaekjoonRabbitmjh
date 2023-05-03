#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

const int MAX = 101000;
vector <vector<int>> v(MAX);
stack <int> st;
int dfsn[MAX], scc[MAX], ans[MAX];
bool vis[MAX];
int sc, cnt;

int dfs(int num) {
	int rst = dfsn[num] = ++cnt;
	st.push(num);

	for (int next : v[num]) {
		if (!dfsn[next])rst = min(rst, dfs(next));
		else if (!vis[next])rst = min(rst, dfsn[next]);
	}
	if (rst == dfsn[num]) {
		while (1) {
			int top = st.top();
			st.pop();
			vis[top] = true;
			scc[top] = sc;

			if (top == num)break;
		}
		sc++;
	}
	return rst;
}

int main() {
	FIO;
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int n, e;
		cin >> n >> e;
		v[n].push_back(e);
	}

	for (int i = 1; i <= n; i++)
		if (!dfsn[i])dfs(i);

	for (int i = 1; i <= n; i++) {
		for (int j : v[i])
			if (scc[i] != scc[j])
				ans[scc[j]]++;
	}
	cnt = 0;
	for (int i = 0; i < sc; i++)
		if (!ans[i])cnt++;
	cout << cnt << endl;

	return 0;
}
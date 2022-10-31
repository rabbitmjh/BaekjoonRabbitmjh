#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
vector <vector <int>> v, res;
int scc[10005], vis[10005];
stack <int> st;
int n, e, cnt, sc;

bool cmp(vector<int> a, vector <int> b) {
	return a[0] < b[0];
}

int dfs(int num) {
	int ret = vis[num] = ++cnt;
	st.push(num);

	for (int next : v[num]) {
		if (vis[next] == -1)
			ret = min(ret, dfs(next));
		else if (scc[next] == -1)
			ret = min(ret, vis[next]);
	}

	if (ret == vis[num]) {
		vector <int> tmp;
		while (1) {
			int top = st.top();
			st.pop();
			scc[top] = sc;
			tmp.push_back(top);
			if (top == num)break;
		}
		sort(tmp.begin(), tmp.end());
		res.push_back(tmp);
		sc++;
	}
	return ret;
}


int main() {
    
	cin >> n >> e;
	v.resize(n + 5);
	memset(vis, -1, sizeof(vis));
	memset(scc, -1, sizeof(scc));
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
		if (vis[i] == -1)dfs(i);

	cout << sc << "\n";
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < sc; i++) {
		for (int j = 0; j < res[i].size(); j++)printf("%d ", res[i][j]);
		cout << "-1\n";
	}
	return 0;
}
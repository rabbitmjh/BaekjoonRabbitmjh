#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
vector <vector<int>> v(5005);
stack <int> st;
int dfsn[5005], scc[5005], vis[5005], sink[5005];
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
			vis[top] = top;
			scc[top] = sc;
			if (top == num)break;
		}
		sc++;
	}
	return rst;
}

int main() {
	while(1){
		int n, e;
		cin >> n;
		if (!n)break;
		cin >> e;

		for (int i = 0; i < e; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
		}
		for (int i = 1; i <= n; i++)
			if (!dfsn[i])dfs(i);
		
		for (int i = 1; i <= n; i++) {
			for (int j : v[i])
				if (scc[i] != scc[j])
					sink[scc[i]]++;
		}

		for (int i = 1; i <= n; i++)
			if (!sink[scc[i]])
				printf("%d ", i);
		cout << endl;

		for (int i = 0; i < 5005; i++)
			v[i].clear();
		memset(vis, false, sizeof(vis));
		memset(dfsn, 0, sizeof(dfsn));
		memset(sink, 0, sizeof(sink));
		memset(scc, 0, sizeof(scc));
		cnt = 0, sc = 0;
	}
	return 0;
}
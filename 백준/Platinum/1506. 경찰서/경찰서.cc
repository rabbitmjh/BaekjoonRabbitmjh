#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

const int MAX = 105;
vector <vector<int>> v(MAX);
stack <int> st;
int cnt, dfsn[MAX], scc[MAX], police[MAX];
ll ans;

int dfs(int num) {
	dfsn[num] = cnt++;
	st.push(num);
	int rst = dfsn[num];

	for (int i = 0; i < v[num].size(); i++) {
		int next = v[num][i];
		if (dfsn[next] == -1)
			rst = min(rst, dfs(next));
		else if (scc[next] == -1)
			rst = min(rst, dfsn[next]);
	}

	if (rst == dfsn[num]) {
		int sum = INT_MAX;
		while (1) {
			int top = st.top();
			st.pop();
			scc[top] = 1;
			sum = min(sum, police[top]);

			if (top == num)
				break;
		}
		ans += sum;
	}
	return rst;
}

int main() {
	FIO;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> police[i];

	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++)
			if (s[j] == '1')
				v[i].push_back(j + 1);
	}
	fill(scc, scc + MAX, -1);
	fill(dfsn, dfsn + MAX, -1);

	for (int i = 1; i <= n; i++) {
		if (dfsn[i] == -1)
			dfs(i);
	}
	cout << ans;

	return 0;
}
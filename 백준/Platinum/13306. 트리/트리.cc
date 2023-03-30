#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, q, parent[200005];
vector <int> v;
stack <pp> st;
stack <string> ans;

int find(int num) {
	if (parent[num] == num)return num;
	return parent[num] = find(parent[num]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[a] = b;
}

int main() {
	FIO;
	cin >> n >> q;
	parent[1] = 1;
	for (int i = 2; i <= n; i++)
		cin >> parent[i];
	
	for (int i = 0; i < (n - 1) + q; i++) {
		int x; cin >> x;
		if (x == 0) {
			int b; cin >> b;
			st.push({ 0,{ b,parent[b] } });
			parent[b] = b; 
		}
		else {
			int c, d; cin >> c >> d;
			st.push({ 1,{c,d} });
		}
	}
	while (!st.empty()) {
		if (st.top().first) {
			int c = st.top().second.first;
			int d = st.top().second.second;
			if (find(c) == find(d))
				ans.push("YES");
			else
				ans.push("NO");
		}
		else {
			uni(st.top().second.second, st.top().second.first);
		}
		st.pop();
	}

	while (!ans.empty()) {
		cout << ans.top() << "\n";
		ans.pop();
	}
	
	return 0;
}
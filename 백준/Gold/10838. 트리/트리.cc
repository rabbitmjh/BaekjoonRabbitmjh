#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k, paint[100005], parent[100005], depth[100005];
set <int> s;

int dfs(int a, int b, int i) {
	if (a == b)return a;
	int cnt = 0;

	while (a && cnt < 1000) {
		depth[a] = i;
		a = parent[a];
		cnt++;
	}

	cnt = 0;
	while (b && cnt < 1000) {
		if (depth[b] == i)
			return b;
		b = parent[b];
	}
	return 0;
}

int main() {
	FIO;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int r, a, b; cin >> r >> a >> b;
		
		if (r == 1) {
			int c; cin >> c;
			int num = dfs(a, b, i);

			while (a != num) {
				paint[a] = c;
				a = parent[a];
			}
			while (b != num) {
				paint[b] = c;
				b = parent[b];
			}
		}
		else if (r == 2)
			parent[a] = b;
		else {
			int ans = dfs(a, b, i);
			while (a != ans) {
				s.insert(paint[a]);
				a = parent[a];
			}
			while (b != ans) {
				s.insert(paint[b]);
				b = parent[b];
			}
			cout << s.size() << "\n";
			s.clear();
		}
	}

	return 0;
}
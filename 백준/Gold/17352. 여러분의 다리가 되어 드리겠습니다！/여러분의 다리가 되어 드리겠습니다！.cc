#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans1, ans2, par[300005];
vector <int> v[300005];

int find(int num) {
	if (par[num] != num)
		return find(par[num]);
	else return par[num];
}
void go(int a, int b) {
	int ap = find(a);
	int bp = find(b);
	if (ap < bp) {
		for (int i = 0;i < v[bp].size();i++) {
			v[ap].push_back(v[bp][i]);
			par[v[bp][i]] = ap;
		}
		v[bp].clear();
	}
	else{
		for (int i = 0;i < v[ap].size();i++) {
			v[bp].push_back(v[ap][i]);
			par[v[ap][i]] = bp;

		}
		v[ap].clear();
	}
}

int main() {
	FIO;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		v[i].push_back(i);
		par[i] = i;
	}

	for (int i = 0;i < n - 2;i++) {
		int a, b;cin >> a >> b;
		if (a < b)
			go(a, b);
		else
			go(b, a);
	}
	for (int i = 1;i <= n;i++) {
		if (v[i].size() > 0 && !ans1)
			ans1 = i;
		else if (v[i].size() > 0 && ans1 != i && !ans2)
			ans2 = i;
	}
	cout << ans1 << " " << ans2;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans, vis1[12], vis2[12];
vector <double> v;


void dfs(double sum, int m) {
	if (sum > 1.01)return;
	if (0.99 <= sum && sum <= 1.01) {
		ans++;
		return;
	}
	for (int i = m; i < n; i++) {
		if (vis1[i] || vis2[i])continue;
		vis2[i] = 1;
		dfs(sum + v[i], i);
		vis2[i] = 0;
	}
	return;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double m; cin >> m;
		v.push_back(1 / m);
	}
	for (int i = 0; i < n; i++) {
		vis1[i] = 1;
		dfs(v[i], i);
	}
	cout << ans;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, st, en, ans;
vector <int> v;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	en = v.size() - 1;

	while (st < en) {
		int sum = v[st] + v[en];
		if (sum > m)
			en--;
		else if (sum < m)
			st++;
		else {
			ans++;
			en--;
			st++;
		}
	}
	cout << ans;
	return 0;
}
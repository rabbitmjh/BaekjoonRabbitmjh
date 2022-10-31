#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, l, r, ans = INT_MAX, sub;
vector <int> v;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	while (l <= r && l < n && r < n) {
		sub = v[r] - v[l];
		if (sub >= m) {
			ans = min(ans, sub);
			l++;
		}
		else r++;
	}
	cout << ans;
	return 0;
}
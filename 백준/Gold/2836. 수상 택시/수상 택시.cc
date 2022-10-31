#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

ll n, m, ans, l = -INT32_MAX, r = -INT32_MAX;
vector <p> v;

int main() {
	FIO;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y; 
		cin >> x >> y;
		if (x < y)
			continue;
		else
			v.push_back({ y,x });

	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (r < v[i].first) {
			ans += r - l;

			l = v[i].first;
			r = v[i].second;
		}
		else
			r = max(r, v[i].second);
	}
	ans += r - l;
	ans = ans * 2 + m;
	cout << ans;
	return 0;
}
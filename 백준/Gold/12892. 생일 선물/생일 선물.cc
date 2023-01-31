#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

ll n, d, ans, sum;
vector <p> v;

int main() {
	FIO;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int l = 0, r = 0;
	while (l <= r && r < n) {
		if (v[r].first - v[l].first < d)
			sum += v[r++].second;
		else sum -= v[l++].second;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
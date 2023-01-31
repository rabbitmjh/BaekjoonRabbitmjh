#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

ll n, m, ans, sum;
vector <ll> v;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		v.push_back(a);
		sum += v[i];
	}
	sort(v.begin(), v.end());
	sum -= n;

	for (int i = 0; i < m; i++) {
		ll tmp = min(v[i], sum / (m - i));
		ans += tmp * tmp;
		sum -= tmp;
	}
	cout << ans;

	return 0;
}
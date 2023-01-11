#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

ll n, t, ans;
vector <p> v;

int main() {
	FIO;
	cin >> n >> t;
	for (int i = 0;i < n;i++) {
		ll a, b;cin >> a >> b;
		v.push_back({ b,a });
	}

	sort(v.begin(), v.end(), greater<p>());

	for (int i = 0;i < v.size();i++)
		ans += v[i].first * (t - i - 1) + v[i].second;
	
	cout << ans << "\n";
	return 0;
}

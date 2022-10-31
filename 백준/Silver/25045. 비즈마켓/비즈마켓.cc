#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, m;
ll ans;
vector <ll> v1, v2;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v1.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int b; cin >> b;
		v2.push_back(b);
	}
	sort(v1.begin(), v1.end(), greater<>());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v2.size(); i++) {
		if (ll(v1[i] - v2[i]) < 0)break;
		else ans += ll(v1[i] - v2[i]);
	}
	cout << ans;
	return 0;
}
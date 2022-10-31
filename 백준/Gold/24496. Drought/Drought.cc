#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <climits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
ll t, n, m, ans;
vector<ll>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> m;
			v.push_back(m);
		}
		if (n == 1) {
			cout << 0 << "\n";
			v.clear();
			ans = 0;
			continue;
		}
		int cnt = 2;
		while (cnt--) {
			for (int i = 1; i < n - 1; i++) {
				if (v[i] > v[i - 1]) {
					ll sub = v[i] - v[i - 1];
					ans += sub * 2;
					v[i] = v[i - 1];
					v[i + 1] -= sub;
				}
			}
			if (v[n - 1] > v[n - 2]) {
				ans = -1;
				break;
			}
			reverse(v.begin(), v.end());
		}
		if (v[0] < 0) ans = -1;
		cout << ans << "\n";
		v.clear();
		ans = 0;
	}
	return 0;
}
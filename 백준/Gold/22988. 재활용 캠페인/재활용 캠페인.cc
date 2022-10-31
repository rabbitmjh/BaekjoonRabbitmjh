#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, ans, st, en, cnt, x;
vector <ll> v;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	en = v.size() - 1;


	while (v[en] >= x) {
		ans++;
		en--;
		cnt++;
		if (en < 0)break;
	}

	while (st < en) {
		if ((v[st] + v[en]) * 2 >= x) {
			st++;
			en--;
			ans++;
			cnt += 2;
		}
		else {
			st++;
		}
	}
	cout << ans + (n - cnt) / 3;

	return 0;
}
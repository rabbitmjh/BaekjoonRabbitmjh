#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <limits.h>
using namespace std;
typedef pair <int, int> p;
typedef long long ll;

ll n, ans;
vector <ll> v;

int main() {
	cin >> n;

	v.push_back(-1e10);
	for (int i = 0; i < n; i++) {
		ll k;
		scanf("%lld", &k);
		if (v.back() < k) {
			v.push_back(k);
			ans++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), k);
			*it = k;
		}
	}
	
	printf("%lld", ans);
	return 0;
}
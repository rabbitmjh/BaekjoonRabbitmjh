#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
#include <set>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>p;
typedef pair<int, p> pp;

p arr[100005];
int main() {
	ll n, m, num = 0, ans = LONG_MAX;
	cin >> n >> m;
	for (int i = 0; i < n; i++)scanf("%lld %lld", &arr[i].first,&arr[i].second);

	int i = 0, j = 0;
	multiset<ll> set;
	while (j <= n) {
		if (num < m) {
			set.insert(arr[j].second);
			num += arr[j++].first;
			continue;
		}
		ans = min(ans, *set.rbegin());
		set.erase(set.find(arr[i].second));
		num -= arr[i++].first;
	}
	cout << ans;
	return 0;
}
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
ll n, k, ans, i, cnt, a;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	while (1) {
		if (!(n & (1ll << i))) {
			if (k & (1ll << cnt)) {
				ans += (1ll << i);
				a += (1ll << cnt);
			}
			cnt++;
		}
		
		if (a == k) {
			cout << ans;
			break;
		}
		i++;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <stack>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, m, ans = 2147483647, cnt;

void dfs(ll num, ll cnt) {
	if (num == m) {
		ans = min(ans, cnt);
		return;
	}
	if (num * 2 <= m)dfs(num * 2, cnt + 1);
	if (num * 10 + 1 <= m)dfs(num * 10 + 1, cnt + 1);
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	dfs(n, 0);

	if (ans == 2147483647)cout << -1;
	else cout << ans + 1;

	return 0;
}
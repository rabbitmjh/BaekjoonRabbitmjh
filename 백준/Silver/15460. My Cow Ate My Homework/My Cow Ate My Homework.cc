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
using namespace std;
typedef long long ll;
typedef pair<string, int>p;
typedef pair<int, p> pp;

ll arr[100005], sum[100005], mn[100005];

int main() {
	ll n, cnt = 0, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);
	
	sum[n - 1] = mn[n - 1] = arr[n - 1];
	for (int i = n - 1; i > 0; i--) {
		sum[i] = sum[i + 1] + arr[i];
		mn[i] = min(mn[i + 1], arr[i]);
	}

	for (int i = 1; i <= n - 2; i++) {
		if ((sum[i + 1] - mn[i + 1])*ans > cnt*(n - i - 1)) {
			cnt = sum[i + 1] - mn[i + 1];
			ans = n - i - 1;
		}
	}

	for (int i = 1; i <= n - 2; i++)
		if ((sum[i + 1] - mn[i + 1]) * ans == cnt * (n - i - 1))printf("%lld\n", i);
	return 0;
}
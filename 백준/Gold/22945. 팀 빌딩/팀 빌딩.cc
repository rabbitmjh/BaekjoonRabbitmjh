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

int n, ans, arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int l = 1, r = n;
	while (l <= r) {
		int m = min(arr[l], arr[r]);
		ans = max(ans, (r - l - 1) * m);

		if (arr[l] > arr[r])r--;
		else l++;
	}

	cout << ans;
	return 0;
}
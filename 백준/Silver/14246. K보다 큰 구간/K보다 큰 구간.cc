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

ll n, k, st, en, ans, sum, arr[100005];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> k;
	while (1) {
		bool check = false;
		sum += arr[en];
		if (sum > k) {
			ans += n - en;
			st++;
			check = true;
		}
		else {
			en++;
		}
		if (check) {
			en = st;
			sum = 0;
		}
		if (en == n)break;
	}

	cout << ans;

	return 0;
}
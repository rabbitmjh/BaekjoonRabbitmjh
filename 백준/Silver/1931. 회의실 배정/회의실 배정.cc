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

p arr[100005];
ll ans, sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].second >> arr[i].first;

	sort(arr, arr + n);

	int ans = 0, end = 0;

	for (int i = 0; i < n; i++) {
		if (end <= arr[i].second) {
			end = arr[i].first;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
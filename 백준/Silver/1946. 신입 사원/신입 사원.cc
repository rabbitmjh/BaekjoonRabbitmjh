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

int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int cnt = 1;
		cin >> n;
		p arr[100005];
		for (int i = 0; i < n; i++)
			cin >> arr[i].first >> arr[i].second;
		sort(arr, arr + n);

		int x = arr[0].first;
		int y = arr[0].second;

		for (int i = 0; i < n; i++) {
			if (x > arr[i].first || y > arr[i].second) {
				cnt++;
				x = arr[i].first;
				y = arr[i].second;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
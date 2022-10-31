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

int t, ans, sum, n, m, k;
vector <int> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		int st = 0, en = m;
		v.clear();
		ans = sum = 0;
		
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}

		for (int i = 0; i < en; i++) {
			sum += v[i];
		}
		if (sum < k)ans++;
		//n==m일때 1가지 밖에 없음
		if (n == m) {
			cout << ans << "\n";
			continue;
		}
		while (en < n + m - 1) {
			sum -= v[st % n];
			sum += v[en % n];
			if (sum < k)ans++;
			st++;
			en++;
		}
		cout << ans << "\n";
	}

	return 0;
}
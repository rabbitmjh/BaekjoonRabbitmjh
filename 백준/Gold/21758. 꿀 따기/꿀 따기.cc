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

int n, ans, sum, l[100005], r[100005];
vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		sum += a;
		l[i] = sum;
	}
	sum = 0;
	for (int i = n - 1; i > -1; i--) {
		sum += v[i];
		r[i] = sum;
	}

	for (int i = 1; i < n - 1; i++)//오른쪽꿀통
		ans = max(ans, 2 * l[n - 1] - v[0] - v[i] - l[i]);
	for (int i = 1; i < n - 1; i++)//왼쪽꿀통
		ans = max(ans, 2 * l[i - 1] + l[n - 2] - l[i]);
	for (int i = 1; i < n - 1; i++)//중간어딘가
		ans = max(ans, l[i] + r[i] - v[0] - v[n - 1]);

	cout << ans;

	return 0;
}
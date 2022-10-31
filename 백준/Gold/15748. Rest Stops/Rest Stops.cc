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
typedef pair<ll, ll>p;
typedef pair<string, p> pp;

ll L, n, a, b, mx, ans, c, d;
p x[100005];
bool check[100005];

int main() {
	cin >> L >> n >> a >> b;
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &x[i].first, &x[i].second);

	for (int i = n - 1; i > -1; i--) {
		if (x[i].second > mx) {
			check[i] = true;
			mx = x[i].second;
		}
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (check[i]) {
			c += (x[i].first - s)*a;
			d += (x[i].first - s)*b;
			ans += (c - d)*x[i].second;
			c = d;
			s = x[i].first;
		}
	}
	cout << ans;


	return 0;
}
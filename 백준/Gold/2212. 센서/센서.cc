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

ll n, k, sum, m;
vector <ll> v, ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	if (n < k) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < v.size(); i++)
		ans.push_back(v[i] - v[i - 1]);
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size() - k + 1; i++)
		sum += ans[i];
	cout << sum;

	return 0;
}
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
ll n, sum;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (ll i = 0; i < n * n; i++) {
		int a; cin >> a;
		sum += a;
	}
	
	cout << sum;

	return 0;
}
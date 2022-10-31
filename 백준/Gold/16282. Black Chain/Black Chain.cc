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
typedef pair<int, int>p;
typedef pair<string, p> pp;

int main() {
	ll n;
	cin >> n;
	ll ans = 2;

	for (int i = 2; i <= 64; i++) {
		ans *= 2;
		long sum = (ans - 1)*i + i - 1;
		if (sum >= n) {
			cout << i - 1 << endl;
			break;
		}
	}
	return 0;
}
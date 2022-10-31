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

int n, k = 1, cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n) {
		if (n < k)
			k = 1;
		n -= k;
		k++;
		cnt++;
	}
	cout << cnt;

	return 0;
}
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
#define mod 987654321

ll n, arr[10005];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	arr[0] = 1; arr[2] = 1;

	for (int i = 4; i <= n; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			arr[i] += arr[j - 2] * arr[i - j];
			arr[i] %= mod;
		}
	}

	cout << arr[n];

	return 0;
}
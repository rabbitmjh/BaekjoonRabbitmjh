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

int n, arr[100005];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	arr[1] = 3, arr[2] = 7;
	for (int i = 3; i <= n; i++)
		arr[i] = (arr[i - 1] * 2 + arr[i - 2]) % 9901;

	cout << arr[n];

	return 0;
}
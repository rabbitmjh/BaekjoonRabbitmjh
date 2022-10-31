#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

int arr[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int ans = 1;
	for (int i = n - m + 1; i <= n; i++)
		ans *= i;
	for (int i = 1; i <= m; i++)
		ans /= i;

	cout << ans;

	return 0;
}
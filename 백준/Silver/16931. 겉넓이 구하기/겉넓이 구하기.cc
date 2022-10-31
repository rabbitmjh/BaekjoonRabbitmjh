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

int n, m, ans;
int arr[105][105];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//m:질량 s:속력 d:방향
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i == 0)ans += arr[i][j];
			if (j == 0)ans += arr[i][j];
			ans += abs(arr[i][j] - arr[i][j + 1]) + abs(arr[i][j] - arr[i + 1][j]);
		}
	ans += n * m * 2;
	cout << ans;

	return 0;
}
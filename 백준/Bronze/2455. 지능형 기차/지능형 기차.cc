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

int arr[5][2];
int n, m;

int main() {
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];

	int sum = 0, ans = 0;
	for (int i = 0; i < 4; i++) {
		sum = sum + arr[i][1] - arr[i][0];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
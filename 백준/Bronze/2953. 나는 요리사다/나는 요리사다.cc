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

int arr[5][4];
int ans[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, ans = 0, a;
	for (int i = 0; i < 5; i++) {
		int n, sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
		if (ans < sum) {
			a = i + 1;
			ans = sum;
		}
	}
	cout << a << " " << ans;

	return 0;
}
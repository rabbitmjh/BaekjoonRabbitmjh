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

int n, arr[2][20], sum[20], ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[0][i] >> arr[1][i];
	
	for (int i = 1; i <= n; i++) {
		int nextT = arr[0][i];
		int nextP = arr[1][i];

		if (i + nextT > n + 1)continue;
		else {
			int last = 0;
			for (int j = 1; j <= i; j++)
				last = max(last, sum[j]);
			sum[i + nextT] = max(last + nextP, sum[i + nextT]);
			ans = max(sum[i + nextT], ans);
		}
	}
	cout << ans;

	return 0;
}
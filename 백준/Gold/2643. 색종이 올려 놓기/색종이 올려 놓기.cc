#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <limits.h>
using namespace std;
typedef pair <int, int> p;
typedef long long ll;

int n, sum;
p arr[1005];
int dp[1005];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i].first = min(a, b);
		arr[i].second = max(a, b);
	}

	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		if (!dp[i]) {
			dp[i] = 1;
		}
		for (int j = 0; j < i; j++) {
			if (arr[i].first >= arr[j].first&&arr[i].second >= arr[j].second) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					sum = max(sum, dp[i]);
				}
			}
		}
	}
	
	cout << sum << endl;

	return 0;
}
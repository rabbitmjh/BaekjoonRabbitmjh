#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int n;
int arr[1005];
int dp[1005];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		if (!dp[i])dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}

	sort(dp, dp + n, greater<int>());
	printf("%d", dp[0]);
	return 0;
}
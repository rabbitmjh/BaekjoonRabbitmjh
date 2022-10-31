#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
int arr[305];
int dp[305];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[1] + arr[2], arr[2] + arr[0]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(arr[i - 1] + arr[i] + dp[i - 3], arr[i] + dp[i - 2]);
	}
	printf("%d", dp[n - 1]);

	return 0;
}
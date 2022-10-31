#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[10005], dp[10005];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int sum = 0;
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		int a = arr[i];
		for (int j = i; j >= 0 && i + 1 - j <= k; j--) {
			a = max(arr[j], a);
			sum = a*(i + 1 - j);
			if (j == 0) dp[i] = max(sum + dp[i + 1], dp[i]);
			else dp[i] = max(sum + dp[j - 1], dp[i]);
		}
	}
	printf("%d", dp[n-1]);
	return 0;
}
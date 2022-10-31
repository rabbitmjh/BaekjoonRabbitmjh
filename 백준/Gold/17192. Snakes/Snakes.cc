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
typedef long long ll;

vector<vector<int>> v;
queue<int> q;

int main() {
	int n, k, dp[401][401], max_s = 0, arr[401], sum = 0;

	for (int i = 0; i < 400; i++)
		for (int j = 0; j < 400; j++)
			dp[i][j] = 1e9;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i]; // 전체 뱀 값

		if (max_s < arr[i]) max_s = arr[i]; // 최대 뱀 길이

		dp[0][i] = max_s * (i + 1);
		dp[i][0] = dp[0][0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			max_s = arr[j];
			for (int m = j - 1; m >= 0; m--) {
				dp[i][j] = min(dp[i][j], dp[i - 1][m] + (j - m)*max_s);
				//뒤에서부터 뱀 마리수 세줘서 곱한것과 현재 값이랑 작은것 비교해서 현재 값에 다시 넣어줌

				max_s = max(arr[m], max_s);
			}
		}
	}
	printf("%d", dp[k][n - 1] - sum);
	return 0;
}
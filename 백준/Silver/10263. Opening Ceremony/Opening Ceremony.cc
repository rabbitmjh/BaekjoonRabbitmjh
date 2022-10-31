#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int arr[100005];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n + 1);
	int ans = n;

	for (int i = 1; i <= n; i++) {
		//arr[i] >> 현재까지 타워 높이(층을 하나씩 없앴을 때)
		//n - i >> 남은 타워 개수(타워를 하나씩 없앴을 때)
		int sum = arr[i] + n - i;
		ans = min(ans, sum);
	}
	printf("%d", ans);
	return 0;
}
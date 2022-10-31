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
int arr[100005];
int sum, ans, cnt;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);

	ans = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] + arr[i - 1] > 0 && arr[i-1] > 0) {
			arr[i] += arr[i - 1];
		}
		if (ans < arr[i])ans = arr[i];
	}
	printf("%d", ans);

	return 0;
}
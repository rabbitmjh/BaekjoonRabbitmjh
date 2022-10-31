#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;

int x[100005], y[100005];
int arr[100005], arr1[100005], sum[100005];

bool cmp(int a, int b) {
	if (arr1[a] == arr1[b])
		return arr[a] > arr[b];
	return arr1[a] < arr1[b];
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		arr[i] = x[i] + y[i];
		arr1[i] = x[i] - y[i];
		sum[i] = i;
	}

	sort(sum, sum + n, cmp);
	int mx = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[sum[i]] > mx) {
			ans++;
			mx = arr[sum[i]];
		}
	}
	printf("%d\n", ans);
	return 0;
}
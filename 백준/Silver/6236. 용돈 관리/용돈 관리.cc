#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

int arr[100005];
int sum;

bool check(int mid,int n,int m) {
	int cnt = 1, cos = mid;

	for (int i = 0; i < n; i++) {
		if (mid < arr[i])return false;
		if (cos - arr[i] < 0) {
			cos = mid;
			cnt++;
		}
		cos -= arr[i];
	}
	return m >= cnt;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	int low = 1, high = sum, ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid, n, m)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	printf("%d\n", ans);

	return 0;
}
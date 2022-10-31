#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

pp arr[105];
int cnt[1005];

int main() {
	int n, mx = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i].first, &arr[i].second.first, &arr[i].second.second);
		mx = max(arr[i].second.first, mx);
	}
	sort(arr, arr + n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cnt[arr[i].second.first] += arr[i].second.second;
		cnt[arr[i].first] -= arr[i].second.second;
	}
	for (int i = 1; i <= mx; i++) {
		sum += cnt[i];
		ans = max(ans, sum*-1);
	}
		

	printf("%d\n", ans);
	return 0;
}
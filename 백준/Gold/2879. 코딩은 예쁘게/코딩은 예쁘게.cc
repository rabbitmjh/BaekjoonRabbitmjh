#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long  long ll;
typedef pair<int, int> p;

int arr[1005];
int arr1[1005];
int sum[1005];
vector <int> v;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++)scanf("%d", &arr1[i]);
	for (int i = 0; i < n; i++)sum[i] = arr[i] - arr1[i];
	int ans = 0, mx = sum[0];
	if (n == 1)printf("%d", abs(sum[0]));
	else {
		
		for (int i = 1; i < n; i++) {
			if (sum[i] >= 0) {
				if (mx < 0) {
					ans += abs(mx);
					mx = sum[i];
				}
				else if (mx < sum[i])mx = sum[i];
				else {
					ans += abs(mx) - abs(sum[i]);
					mx = sum[i];
				}
			}
			else {
				if (mx > 0) {
					ans += abs(mx);
					mx = sum[i];
				}
				else if (mx > sum[i])mx = sum[i];
				else {
					ans += abs(mx) - abs(sum[i]);
					mx = sum[i];
				}
			}
		}
	}
	ans += abs(mx);
	printf("%d", ans);
	return 0;
}
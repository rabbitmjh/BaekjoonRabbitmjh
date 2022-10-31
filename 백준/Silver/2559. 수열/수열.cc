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
typedef long double ld;
typedef pair<int, int> p;
int n, m;
int arr[100005];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int ans = 0, sum = 0;
	for (int i = 0; i < m; i++)
		sum += arr[i];
	ans = sum;
	for (int i = 0; i < n - m; i++) {
		sum -= arr[i];
		sum += arr[m + i];
		ans = max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}
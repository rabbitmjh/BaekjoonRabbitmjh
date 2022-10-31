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
typedef pair<ll, ll>p;
typedef pair<string, p> pp;

int n, arr[100005];
int sum, ans, cnt = -1;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (arr[0] > 0) {
		printf("-1");
		return 0;
	}
	arr[0] = 0;

	for (int i = n - 1; i > -1; i--) {
		if (cnt != -1 && arr[i] != -1 && arr[i] != cnt) {
			cout << -1 << '\n';
			return 0;
		}
		if (cnt == -1)	cnt = arr[i];
		if (arr[i] == -1) arr[i] = cnt;
		if (arr[i] == 0) ans++;
		if (arr[i] == -1)sum++;
		if (cnt > -1) cnt--;
	}
	printf("%d %d", ans, sum + ans);

	return 0;
}
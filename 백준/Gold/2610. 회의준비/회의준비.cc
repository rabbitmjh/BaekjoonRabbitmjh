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
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;

int n, m, K;
int arr[105][105], sum[105], ans[105], ans1[105], cnt;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = (i == j ? 0 : 1e9);

	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j]<1e9&&arr[i][j]>sum[i])
				sum[i] = arr[i][j];

	for (int i = 1; i <= n; i++) {
		if (!ans1[i]) {
			int a = i;
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] < 1e9) {
					ans1[j] = 1;
					if (sum[a] > sum[j])
						a = j;
				}
			}
			ans[cnt++] = a;
		}
	}
	sort(ans, ans + cnt);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
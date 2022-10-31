#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, cnt;
int arr[1000005];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i]) {
			if (i == 1)cnt++;
			else {
				if (!arr[i - 1]) {
					cnt++;
				}
			}
		}
	}

	while (m--) {
		int a,dirty;
		scanf("%d", &a);
		if (a) {
			scanf("%d", &dirty);
			if (arr[dirty])continue;
			arr[dirty] = 1;
			if (dirty == 1) {
				if (!arr[dirty + 1]) {
					cnt++;
					continue;
				}
			}
			else if (dirty == n) {
				if (!arr[dirty - 1]) {
					cnt++;
					continue;
				}
			}
			if (arr[dirty - 1] && arr[dirty + 1]) {
				cnt--;
				continue;
			}
			if (!arr[dirty - 1] && !arr[dirty + 1])cnt++;
		}
		else printf("%d\n", cnt);
	}


	return 0;
}
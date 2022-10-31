#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string.h>
using namespace std;


int arr[1005][2];
int wa[1005];
int main() {
	int t;
	double S, A;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		int a, b, p, q;
		int check = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d %d", &a, &b, &p, &q);
			if (p != 0) {
				arr[a][0] += p;
				arr[b][1] += p;
			}
			if (q != 0) {
				arr[a][1] += q;
				arr[b][0] += q;
			}
		}
		for (int i = 1; i <= n; i++) {
			S = arr[i][0];
			A = arr[i][1];
			if (S == 0 && A == 0) {
				check = 1;
			}
			else {
				double ans = (S * S) * 1000 / (S * S + A * A);
				wa[i] = (int)ans;
			}
		}
		sort(wa, wa + n+1);
		int z = wa[n];
		int x = wa[1];
		printf("%d\n", z);
		if (check == 0)printf("%d\n", x);
		else printf("0\n");
		memset(arr, 0, sizeof(arr));
		memset(wa, 0, sizeof(wa));
	}
}



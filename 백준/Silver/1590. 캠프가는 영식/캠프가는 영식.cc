#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <cstring>
using namespace std;

int n, t,sum=1000000005;
int arr[100005][3], a,b,c,brr[100005];
int main() {
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
		brr[i] = arr[i][0];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i][2]; j++) {
			if (arr[i][2] >= 0) {
				if (brr[i] - t < sum&&brr[i] - t >= 0) {
					sum = brr[i] - t;
				}
				brr[i] += arr[i][1];
			}
		}
	}
	if (sum == 1000000005) {
		printf("-1");
	}
	else printf("%d",sum);

	return 0;
}
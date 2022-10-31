#include<stdio.h>
int cost[50002], n,q=-1,sum;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i]);
		if (cost[i] > q) {
			q = cost[i];
		}
		sum += cost[i];
	}
	sum = sum - q;
	printf("%d", sum);
	return 0;
}
#include<stdio.h>
int snack, n, money;
int main() {
	scanf("%d %d %d", &snack, &n, &money);
	if (snack*n - money > 0) {
		printf("%d", snack*n - money);
	}
	else printf("0");
	return 0;
}
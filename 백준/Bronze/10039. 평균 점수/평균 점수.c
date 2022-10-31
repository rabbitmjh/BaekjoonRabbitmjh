#include<stdio.h>
int main() {
	int a[5], sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 5; i++) {
		if (a[i] < 40) {
			a[i] = 40;
		}
		sum += a[i];
	}
	sum = sum / 5;
	printf("%d", sum);
	return 0;
}
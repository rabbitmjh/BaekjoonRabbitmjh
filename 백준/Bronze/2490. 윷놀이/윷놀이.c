#include<stdio.h>
int main() {
	int a[4],b[4],c[4],sum=0,sum1=0,sum2=0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 4; i++) {
		sum += a[i];
	}
	if (sum == 4) {
		printf("E");
	}
	else if (sum == 1) {
		printf("C");
	}
	else if (sum == 2) {
		printf("B");
	}
	else if (sum == 3) {
		printf("A");
	}
	else if (sum == 0) {
		printf("D");
	}
	printf("\n");

	for (int i = 0; i < 4; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < 4; i++) {
		sum1 += b[i];
	}
	if (sum1 == 4) {
		printf("E");
	}
	else if (sum1 == 1) {
		printf("C");
	}
	else if (sum1 == 2) {
		printf("B");
	}
	else if (sum1 == 3) {
		printf("A");
	}
	else if (sum1 == 0) {
		printf("D");
	}
	printf("\n");

	for (int i = 0; i < 4; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < 4; i++) {
		sum2 += c[i];
	}
	if (sum2 == 4) {
		printf("E");
	}
	else if (sum2 == 1) {
		printf("C");
	}
	else if (sum2 == 2) {
		printf("B");
	}
	else if (sum2 == 3) {
		printf("A");
	}
	else if (sum2 == 0) {
		printf("D");
	}
	return 0;
}
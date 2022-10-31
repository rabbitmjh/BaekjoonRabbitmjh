#include<stdio.h>
int main(void) {
	int i, j, k, l;
	scanf("%d", &i);
	for (j = 0; j < i; j++) {
		for (k = 0; k < j; k++) {
			printf(" ");
		}
		for (l = 0; l < i - j; l++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
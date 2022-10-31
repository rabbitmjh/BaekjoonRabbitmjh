#include<stdio.h>
int main(void) {
	int A, B, C, D, E;
	scanf("%d", &A);
	B = A / 3;
	C = A % 3;
	D = A / 5;
	E = A % 5;
	if (A < 10) {
		if (C == 0) {
			printf("%d", B);
		}
		else if (E % 3 == 0) {
			B = E / 3;
			printf("%d", D + B);
		}
		else
			printf("%d", -1);
	}
	else if (A >= 10) {
		if (E == 0) {
			printf("%d", D);
		}
		else if (E == 1) {
			printf("%d", D + 1);
		}
		else if (E == 2) {
			printf("%d", D + 2);
		}
		else if (E == 3) {
			printf("%d", D + 1);
		}
		else if (E == 4) {
			printf("%d", D + 2);
		}
	}
	return 0;
}
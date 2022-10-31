#include<stdio.h>
int main(void) {
	double A, B, C;
	scanf("%lf %lf", &A, &B);
	C = A / B;
	printf("%.9lf", C);
	return 0;
}
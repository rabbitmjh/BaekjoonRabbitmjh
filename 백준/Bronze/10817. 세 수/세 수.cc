#include<stdio.h>
int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (A >= B) {
		if (A >= C) {
			if (B >= C) {
				printf("%d", B);
			}
			else {
				printf("%d", C);
			}
		}
		else if (C >= A) {
			printf("%d", A);
		}
	}
	else if (B >= A) {
		if (B >= C) {
			if (A >= C) {
				printf("%d", A);
			}
			else {
				printf("%d", C);
			}
		}
		else if (B <= C) {
			printf("%d", B);
		}
	}
	return 0;
}
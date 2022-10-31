#include<stdio.h>
int n1, n2;
int main() {
	for (int i = 0;; i++) {
		scanf("%d %d", &n1, &n2);
		if (n1 + n2 == 0) return 0;
		if (n1%n2 == 0) {
			printf("multiple\n");
		}
		else if (n2%n1 == 0) {
			printf("factor\n");
		}
		else printf("neither\n");
	}
	return 0;
}
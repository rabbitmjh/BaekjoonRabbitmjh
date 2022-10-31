#include<stdio.h>
int a = 1, b, c, n1, n2, d, n, i;
int ball(int n) {
	if (a == 1) d = 1;
	else if (b == 1) d = 2;
	else if (c == 1)d = 3;
	if (n == 0) return 0;
	i = 0;
	scanf("%d %d", &n1, &n2);
	if (n1 == n2) {
		if (n == 1) {
			printf("%d", d);
			return 0;
		}
		return ball(n - 1);
	}
	if (n1 + n2 == 3) {
		i = a;
		a = b;
		b = i;
		return ball(n - 1);
	}
	if (n1 + n2 == 4) {
		i = a;
		a = c;
		c = i;
		return ball(n - 1);
	}
	if (n1 + n2 == 5) {
		i = b;
		b = c;
		c = i;
		return ball(n - 1);
	}
}
int main() {
	scanf("%d", &n);
	ball(n);
	printf("%d", d);
}

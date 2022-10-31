#include<cstdio>
#include<iostream>

long a, b, c,sum,q;
int x[9];
int main() {
	scanf("%ld %ld %ld", &a, &b, &c);
	sum = a * b * c;
	while (sum != 0) {
		q = sum % 10;
		x[q]++;
		sum = sum / 10;
	}
	for (int i = 0; i <= 9; i++)printf("%d\n", x[i]);
	return 0;
}
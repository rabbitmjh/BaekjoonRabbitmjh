#include<stdio.h>
int hp, mp, atk, def, sum=0,n,a,b,c,d;
int force(int n) {
	if (n == 0)
		return 0;
	sum = 0;
	scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &atk, &def, &a, &b, &c, &d);
	if (hp + a < 1) {
		sum += 1;
	}
	else if (hp + a >= 1) {
		sum += (hp + a);
	}
	if (mp + b < 1) {
		sum += 5;
	}
	else if (mp + b >= 1) {
		sum += (mp + b) * 5;
	}
	if (atk + c < 0) {
		sum += 0;
	}
	else if (atk + c>= 0) {
		sum += (atk + c) * 2;
	}
	sum += (def + d) * 2;
	printf("%d\n", sum);
	return force(n - 1);
}
int main() {
	scanf("%d", &n);
	force(n);

	return 0;
}
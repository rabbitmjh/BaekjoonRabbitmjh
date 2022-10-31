#include<cstdio>
#include<iostream>

using namespace std;
long long sum, a[85];
int n;
int main() {
	scanf("%d", &n);
	a[1] = 1;
	a[2] = 1;

	for (int i = 3; i <= n + 1; i++) {
		a[i] = a[i - 1] + a[i - 2];
		sum = (a[i] + a[i - 1]) * 2;
	}

	if (n == 1) {
		sum = 4;
	}
	if (n == 2) {
		sum = 6;
	}
	printf("%lld", sum);
	return 0;
}
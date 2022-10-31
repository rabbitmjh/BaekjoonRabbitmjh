#include<cstdio>
#include<iostream>

using namespace std;
long long a[95];
int n, i;
int main() {
	scanf("%d", &n);
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;

	for (i = 3; i <= n + 1; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	printf("%lld", a[n]);
	return 0;
}
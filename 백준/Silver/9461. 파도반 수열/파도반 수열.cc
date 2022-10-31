#include<cstdio>
#include<iostream>
using namespace std;
int n,sum;
long long a[105] = { 1,1,1,1,2,2, };
int main() {
	for (int i = 6; i <= 105; i++) {
		a[i] = a[i - 1] + a[i - 5];
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sum);
		printf("%lld\n", a[sum]);
	}
	return 0;
}
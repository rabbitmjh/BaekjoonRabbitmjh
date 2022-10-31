#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[1005],b;
int main() {
	scanf("%d", &n);
	a[1] = 3;
	for (int i = 2; i <= n; i++) {
		b = 0;
		for (int j = 1; j <= i; j++) {
			b += j;
		}
		a[i] = a[i - 1] + b +i*(i+1);
	}
	printf("%d", a[n]);
	return 0;
}
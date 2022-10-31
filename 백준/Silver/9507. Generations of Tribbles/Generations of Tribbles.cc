#include<cstdio>
#include<iostream>

int n,test_case;
long long koong[67] = { 1,1,2,4, };
int main() {
	scanf("%d", &n);
	for (int i = 4; i <= 67; i++) {
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &test_case);
		printf("%lld\n", koong[test_case]);
	}
	return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;
int n, n1,n2;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &n1, &n2);
		printf("Case #%d: %d + %d = %d\n",i,n1,n2, n1 + n2);
	}
	return 0;
}
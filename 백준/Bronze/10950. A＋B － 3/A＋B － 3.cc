#include<cstdio>
#include<iostream>
using namespace std;
int n, n1,n2;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &n1, &n2);
		printf("%d\n", n1 + n2);
	}
	return 0;
}
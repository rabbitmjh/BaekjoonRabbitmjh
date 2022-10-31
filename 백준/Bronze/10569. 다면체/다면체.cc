#include<cstdio>
#include<iostream>
using namespace std;

int n,n1,n2,sum;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &n1, &n2);
		printf("%d\n", 2 + n2 - n1);
	}
	return 0;
}
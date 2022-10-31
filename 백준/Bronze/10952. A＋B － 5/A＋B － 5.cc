#include<cstdio>
#include<iostream>
using namespace std;
int n, n1,n2;

int main() {
	while (n=1) {
		scanf("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0)break;
		printf("%d\n", n1 + n2);
	}
	return 0;
}
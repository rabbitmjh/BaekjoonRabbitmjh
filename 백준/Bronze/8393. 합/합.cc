#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, n1;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		n1 += i;
	}
	printf("%d", n1);
	return 0;
}
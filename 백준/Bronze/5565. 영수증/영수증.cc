#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, n1;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &n1);
		n -= n1;
	}
	printf("%d", n);
	return 0;
}
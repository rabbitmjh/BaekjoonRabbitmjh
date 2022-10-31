#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, n1,sum;
int main() {
	scanf("%d %d", &n, &n1);
	sum = n1 * 2 - n;
	printf("%d", sum);
	return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;

int n, sum[45];
int main() {
	cin >> n;
	sum[1] = 1;
	for (int i = 2; i <= n+2; i++) {
		sum[i] = sum[i - 1] + sum[i - 2];
	}
	printf("%d", sum[n]);
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k, m, sum, s, u;
int arr[10005], a[105];
int gcd(int n, int k) {
	return k ? gcd(k,n%k) : n;
}
int main() {
	scanf("%d %d", &n, &k);
	if (n == 0 && k == 0) {
		printf("0");
		return 0;
	}
	if (n < 0) {
		n = n * -1;
	}
	if (k < 0) {
		k = k * -1;
	}
	if (n > k) {
		m = k;
		k = n;
		n = m;
	}

	if (gcd(n,k)!=1) {
		printf("2");
	}
	else {
		printf("1");
	}
		return 0;
}
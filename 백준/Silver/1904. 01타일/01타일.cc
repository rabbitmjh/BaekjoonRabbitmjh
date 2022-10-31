#include<iostream>
using namespace std;
long t,n,m;
long arr[1000005];
int main() {
	scanf("%ld", &n);
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%15746;
	}
	printf("%ld", arr[n]);
	
	return 0;
}
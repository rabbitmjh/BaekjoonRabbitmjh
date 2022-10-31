#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<string.h>
using namespace std;
long long n,m,sum[1000005];

int main() {
	cin >> n;
	sum[0] = 0;
	sum[1] = 1;
	for (long i = 2; i <= n; i++) {
		sum[i] = (sum[i - 1] + sum[i - 2])%1000000007;
	}
	printf("%lld", sum[n]%1000000007);
	return 0;
}
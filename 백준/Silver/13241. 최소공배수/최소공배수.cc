#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long n, m;
int gcd(long long n, long long m) {
	return m ? gcd(m, n%m) : n;
}
int main() {
	cin >> n >> m;
	if (n > m) {
		long long a = m;
		m = n;
		n = a;
	}
	printf("%lld", n*m / gcd(n, m));
	return 0;
}
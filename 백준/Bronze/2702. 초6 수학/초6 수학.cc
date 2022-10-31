#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m,k;
int gcd(int n, int m) {
	return m ? gcd(m, n%m) : n;
}
int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n >> m;
		if (n > m) {
			int a = m;
			m = n;
			n = a;
		}
		printf("%d ", n*m / gcd(n, m));
		printf("%d\n", gcd(n, m));
	}
	return 0;
}
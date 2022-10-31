#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
long long n, m[120], a;
int main() {
	cin >> n;
	m[1] = 1, m[2] = 1, m[3] = 1;
	for (int i = 4; i <= n; i++) {
		m[i] = m[i - 1] + m[i - 3];
	}
	printf("%lld", m[n]);
	return 0;
}
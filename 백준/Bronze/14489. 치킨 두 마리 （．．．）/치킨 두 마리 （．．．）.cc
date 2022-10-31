#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
long long n, m, a;
int main() {
	cin >> n >> m >> a;
	if (n + m < a*2) {
		cout << n + m;
	}
	else {
		cout << (n + m) - a*2;
	}
	return 0;
}
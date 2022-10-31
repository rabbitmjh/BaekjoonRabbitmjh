#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n,n1,n2,n3,sum,k;
int main() {
	scanf("%d", &n);
	if (n < 100)
		printf("%d", n);
	else {
		for (int i = 100; i <= n; i++) {
			n1 = i % 10;
			k = i / 10;
			n2 = k % 10;
			n3 = k / 10;
			if (n1 - n2 == n2 - n3)sum++;
		}
		printf("%d", sum + 99);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n,i,k;
int sum(int n) {
	for (int l = 1; l < n; l++) {
		k = l;
		i = 0;
		while (k != 0) {
			i += k % 10;
			k = k / 10;
		}
		if (i + l == n)
			return l;
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}
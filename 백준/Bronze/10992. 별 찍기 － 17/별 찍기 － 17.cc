#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int n,v=1;

int main() {
	cin >> n;
	int c = 2 * n - 1;
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			for (int j = 0; j < c; j++) {
				printf("*");
			}
			return 0;
		}
		for (int j = 1; j <= n-i; j++) {
			printf(" ");
		}
		printf("*");
		if (i == 1) {
			printf("\n");
			continue;
		}
		for (int j = 1; j <= v; j++) {
			printf(" ");
		}
		v += 2;
		printf("*\n");
	}

	return 0;
}

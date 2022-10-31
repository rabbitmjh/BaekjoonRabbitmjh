#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int n, m;

int main() {
	int j=1;
	scanf("%d %d", &n, &m);
	for (int i = 1;(i*j)<=m; i++) {
		for (j;(i*j)<=m; j++) {
			if (i*j == m) {
				if ((i + 2) * 2 + (j * 2) == n) {
					printf("%d %d", j+2, i+2);
					return 0;
				}
			}
		}
		j = 1;
	}

	return 0;
}
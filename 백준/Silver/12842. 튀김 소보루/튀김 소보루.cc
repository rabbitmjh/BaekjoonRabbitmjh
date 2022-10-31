#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int n, s, m, arr[100005];

int main() {
	scanf("%d %d", &n, &s);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &arr[i]);
	}
	int j = 0;
	int a = n - s;
	int sum = 0;
	while (a) {
		if (j == 0) {
			for (int i = 1; i <= m; i++) {
				a--;
				if (a == 0) {
					printf("%d", i);
					return 0;
				}
			}
		}
		j++;
		for (int i = 1; i <= m; i++) {
			if (j % arr[i] == 0) {
				a--;
				if (a == 0) {
					printf("%d", i);
					return 0;
				}
			}
		}

	}
}
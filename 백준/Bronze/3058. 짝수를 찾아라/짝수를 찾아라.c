#include <stdio.h>
int main() {
	int a[7], sum = 0, num;
	scanf("%d", &num);
	for (int j = 0; j < num; j++) {
		for (int i = 0; i < 7; i++) {
			scanf("%d", &a[i]);
		}
		int small = 1e9;
		sum = 0;
			for (int i = 0; i < 7; i++) {
				if (a[i] % 2) {
					continue;
				}
				sum += a[i];
				if (small > a[i])
					small = a[i];
			}
		printf("%d %d\n", sum, small);
	}
	return 0;
}
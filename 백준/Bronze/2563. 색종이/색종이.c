#include<stdio.h>
int paper[104][104];
int main() {
	int num, x, y, sum = 0, j = 0, k = 0, z;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &x, &y);
		j = y + 10;
		k = x + 10;
		z = x;
		for (y; y < j; y++) {
			x = z;
			for (x; x < k; x++) {
				paper[y][x] = 1;
			}
		}
	}
	for (y = 0; y < 100; y++) {
		for (x = 0; x < 100; x++) {
			if (paper[y][x] == 1) {
				sum++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
#include<stdio.h>
int many[1001];
int main() {
	int num[11], x, i, j, sum = 0, m = 0, mode;
	for (i = 0; i < 10; i++) {
		scanf("%d", &x);
		j = i + 1;
		num[j] = x;
		sum += x;
	}
	for (int k = 0; k < 10; k++) {
		int l = k + 1;
		many[num[l]]++;
	}
	for (int k = 0; k < 1000; k++) {
		int l = k + 1;
		if (many[l] >= m) {
			m = many[l];
			mode = l;
		}
	}
	printf("%d\n%d", sum / 10, mode);
	return 0;
}
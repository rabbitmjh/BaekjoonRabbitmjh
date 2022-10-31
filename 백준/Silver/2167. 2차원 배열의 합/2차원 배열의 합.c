#include <stdio.h>
int num[301][301];
int main() {
	int n, m, i, j, x, y, sum = 0, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &num[i][j]);
			}
	}
	scanf("%d", &k);
	for (int q = 0; q < k; q++) {
		i = 0;
		j = 0;
		x = 0;
		y = 0;
		scanf("%d %d %d %d", &j, &i, &y, &x);
		j = j - 1;
		int l = i;
		for (j; j < y; j++) {
			i = l - 1;
			for (i; i < x; i++) {
				sum += num[j][i];
			}
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}
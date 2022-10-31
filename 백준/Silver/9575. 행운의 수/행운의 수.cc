#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
#include <string.h>

int t;
int num[3], comp[3][55], number[90005];

int check(int n) {
	if (number[n]) return 0;
	number[n] = true;
	int ans = n, flag = 0;
	while (ans > 0) {
		if (((ans % 10) != 5) && (ans % 10) != 8) { flag = 1; break; }
		ans /= 10;
	}
	if (flag) return 0;
	else return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		int jung = 0;
		memset(num, 0, sizeof(num));
		memset(comp, 0, sizeof(comp));
        memset(number,0,sizeof(number));
		for (int i = 0; i < 3; i++) {
			scanf("%d", &num[i]);
			for (int j = 0; j < num[i]; j++) {
				scanf("%d", &comp[i][j]);
			}
		}
		for (int i = 0; i < num[0]; i++) {
			for (int j = 0; j < num[1]; j++) {
				for (int k = 0; k < num[2]; k++) {
					int answer = check(comp[0][i] + comp[1][j] + comp[2][k]);
					if (answer) jung++;
				}
			}
		}
		printf("%d\n", jung);
	}
}
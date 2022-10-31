#include<stdio.h>
int box[102][102], n, ny, nx,sum,nny;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		sum = 0;
		scanf("%d %d", &ny, &nx);
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nx; k++) {
				scanf("%d", &box[j][k]);
			}
		}
		
		for (int j = 0; j < ny -1; j++) {
			for (int k = 0; k < nx ; k++) {
				if (box[j][k] == 1) {
					nny = ny;
					for (nny-1 ; nny -1 > j; nny--) {
						if (box[nny -1][k] == 0) {
							box[nny-1][k] = 1;
							sum += nny - 1 - j;
							box[j][k] = 0;
							break;
						}
					}
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
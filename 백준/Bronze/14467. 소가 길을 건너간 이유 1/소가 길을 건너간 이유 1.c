#include<stdio.h>
int cow[10][2];
int main() {
	int n,y=0,x=0,sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &y);
		scanf("%d", &x);
		int k = y;
		y = y - 1;
		if (cow[y][0] == 0) {
			cow[y][0] = k;
			cow[y][1] = x;
		}
		else if (cow[y][0] != 0) {
			if (cow[y][1] != x) {
				cow[y][1] = x;
				sum++;
			}
		}		
	}
	printf("%d", sum);
	return 0;
}
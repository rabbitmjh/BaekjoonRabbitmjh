#include <stdio.h>
int a[105];
int main() {
	int son, chair,sum=0;
	scanf("%d", &son);
	for (int i = 0; i < son; i++) {
		scanf("%d", &chair);
		if (a[chair] == 0) {
			a[chair] = 1;
		}
		else if (a[chair] != 0) {			
			sum ++;
		}
	}
	printf("%d", sum);
	return 0;
}
#include<stdio.h>
int school, stu[105], app[105],n,nam;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &stu[i], &app[i]);
		if (app[i] % stu[i] < 0) {
			nam += 0;
		}
		else if (app[i] % stu[i] >= 0) {
			nam += app[i] % stu[i];
		}
	}
	printf("%d", nam);
	return 0;
}
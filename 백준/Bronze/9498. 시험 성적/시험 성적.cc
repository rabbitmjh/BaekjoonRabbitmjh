#include<stdio.h>
int main(void) {
	int exam;
	scanf("%d", &exam);
	if (exam >= 90) {
		printf("A");
	}
	else if (exam >= 80) {
		printf("B");
	}
	else if (exam >= 70) {
		printf("C");
	}
	else if(exam >= 60) {
		printf("D");
	}
	else
		printf("F");
	return 0;
}

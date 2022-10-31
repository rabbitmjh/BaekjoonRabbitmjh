#include<stdio.h>
int main(void) {
	int i, num, num1, num10, newnum,a,cnt=0;
	scanf("%d", &num);
	newnum = num;
	for (i = 0; newnum != num||i==0; i++) {
		num10 = newnum / 10;
		num1 = newnum % 10;
		a = (num1 + num10)%10;
		newnum = num1 * 10 + a;
	}
	printf("%d", i);
	return 0;
}
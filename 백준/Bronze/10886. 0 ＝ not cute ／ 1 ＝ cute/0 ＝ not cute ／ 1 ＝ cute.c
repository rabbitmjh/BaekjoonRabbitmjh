#include<stdio.h>
int n,s,yes,no;
int poll(int n) {
	if (n == 0) return 0;
	scanf("%d", &s);
	if (s == 1) {
		yes++;
	}
	else {
		no++;
	}
	poll(n - 1);
}	
int main() {
	scanf("%d", &n);
	poll(n);
	if (yes > no) {
		printf("Junhee is cute!");
	}
	else if (yes < no) {
		printf("Junhee is not cute!");
	}
	return 0;
}
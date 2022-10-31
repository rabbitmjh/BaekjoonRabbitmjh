#include<stdio.h>
int n,a[30006],s,j,b[30006],high;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	j = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < j) {
			s++;
			b[i] = s;
		}
		else {
			j = a[i];
			s = 0;
		}	
	}
	
	for (int i = 0; i < 30006; i++) {
		if (b[i] > high) {
			high = b[i];
		}
	}
	printf("%d", high);
	return 0;
}
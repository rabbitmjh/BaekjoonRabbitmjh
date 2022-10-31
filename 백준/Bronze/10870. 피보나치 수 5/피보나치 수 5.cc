#include<iostream>
#include<cstdio>
int n, arr[21] = { 0,1, };
int main() {
	scanf("%d", &n);
	for (int i = 2; i < 21; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%d", arr[n]);
	return 0;
}
#include<iostream>
using namespace std;
long t,n,m;
long arr[35][35];
int main() {
	scanf("%ld", &t);
	arr[1][1] = 1;
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (int i = 0; i < t; i++) {
		scanf("%ld %ld", &n, &m);
		printf("%ld\n", arr[m+1][n+1]);
	}
	
	return 0;
}
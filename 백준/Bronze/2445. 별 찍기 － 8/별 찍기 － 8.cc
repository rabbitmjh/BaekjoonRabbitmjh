#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		for (int j = 0; j < n * 2 - i * 2; j++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n-1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		for (int j = 0; j < n * 2 - i * 2; j++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
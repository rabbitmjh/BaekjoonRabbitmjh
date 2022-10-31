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
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < i * 2 - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < i * 2 - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
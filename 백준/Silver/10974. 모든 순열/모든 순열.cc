#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int arr[9], check[9],n,n1;
void s(int l, int n) {
	if (l == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				check[i] = 1;
				arr[l] = i;
				s(l + 1, n);
				check[i] = 0;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	s(0, n);
	return 0;
}
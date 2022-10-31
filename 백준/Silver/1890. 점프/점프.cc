#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long n;
long long check[105][105];
long long arr[105][105];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	check[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] == 0 ||arr[i][j]==0) continue;

			long long down = i + arr[i][j];
			long long right = j + arr[i][j];

			if (down <= n) {
				check[down][j] += check[i][j];
			}
			if (right <= n) {
				check[i][right] += check[i][j];
			}
		}
	}
	printf("%lld", check[n][n]);

	return 0;
}

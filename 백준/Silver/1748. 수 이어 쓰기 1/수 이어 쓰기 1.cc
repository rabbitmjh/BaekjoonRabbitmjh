#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
char arr[10][10];
int n, n1, sum;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i / 100000000==1) {
			sum += 9;
		}
		else if (i / 10000000 >= 1) {
			sum += 8;
		}
		else if (i / 1000000 >= 1) {
			sum += 7;
		}
		else if (i / 100000 >= 1) {
			sum += 6;
		}
		else if (i / 10000 >= 1) {
			sum += 5;
		}
		else if (i / 1000 >= 1) {
			sum += 4;
		}
		else if (i / 100 >= 1) {
			sum += 3;
		}
		else if (i / 10 >= 1) {
			sum += 2;
		}
		else if (i / 1 >= 1) {
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}

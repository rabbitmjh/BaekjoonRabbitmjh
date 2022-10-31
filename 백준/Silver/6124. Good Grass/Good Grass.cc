#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>
#include <limits.h>
using namespace std;
typedef long long ll;

int nr, nc;
int arr[105][105];

int main() {
	cin >> nr >> nc;
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int cnt = 0;
	int x = 0, y = 0;
	for (int i = 0; i < nr-3; i++) {
		for (int j = 0; j < nc-3; j++) {
			int sum = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 3; l++) {
					sum += arr[k][l];
				}
			}
			if (cnt < sum) {
				cnt = sum;
				x = i;
				y = j;
			}
		}
	}
	printf("%d\n%d %d", cnt, x+1, y+1);

	return 0;
}
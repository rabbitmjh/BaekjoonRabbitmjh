#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

char arr[105][105];
int ans[105][105];
int check[105][105];
int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		scanf("%s", &arr[i]);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a = j, cnt = 0;
			while (1) {
				if (a < 0) {
					ans[i][j] = -1;
					break;
				}
				if (arr[i][a] == 'c') {
					if (check[i][j]) {
						ans[i][j] = min(ans[i][j], cnt);
						break;
					}
					ans[i][j] = cnt;
					check[i][j] = 1;
					break;
				}
				cnt++;
				a--;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}

	return 0;
}
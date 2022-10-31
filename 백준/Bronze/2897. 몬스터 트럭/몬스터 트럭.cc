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

char arr[55][55];
int ans[5];
int check[55][55];

int main() {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		scanf("%s", arr[i]);

	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < c - 1; j++) {
			int cnt = 0;
			if (arr[i][j] == '#' || arr[i + 1][j] == '#' || arr[i][j + 1] == '#' || arr[i + 1][j + 1] == '#')continue;
			if (arr[i][j] == 'X')cnt++;
			if (arr[i + 1][j] == 'X')cnt++;
			if (arr[i][j + 1] == 'X')cnt++;
			if (arr[i + 1][j + 1] == 'X')cnt++;

			ans[cnt]++;
		}
	}
	for (int i = 0; i <= 4; i++)printf("%d\n", ans[i]);

	return 0;
}
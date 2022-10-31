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

char arr[15][15];
int ans[15][15];
int check[15][15];

int main() {
	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		string s;
		cin >> s;

		for (int j = 1; j <= c; j++)
			arr[i][j] = s[j - 1];
	}
	for (int i = 0; i <= r + 1; i++)
		for (int j = 0; j <= c + 1; j++)
			if (arr[i][j] == 0)arr[i][j] = '.';

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int cnt = 0;
			if (arr[i][j] == 'X') {
				if (arr[i - 1][j] == '.' || arr[i - 1][j] == '0')cnt++;
				if (arr[i + 1][j] == '.' || arr[i + 1][j] == '0')cnt++;
				if (arr[i][j + 1] == '.' || arr[i][j + 1] == '0')cnt++;
				if (arr[i][j - 1] == '.' || arr[i][j - 1] == '0')cnt++;
			}
			if (cnt > 2)check[i][j] = 1;
		}
	}

	int mnX = 20, mnY = 20, mxX = -1, mxY = -1;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			if (check[i][j] == 1)arr[i][j] = '.';
			if (arr[i][j] == 'X') {
				mnX = min(mnX, i);
				mnY = min(mnY, j);
				mxX = max(mxX, i);
				mxY = max(mxY, j);
			}
		}

	for (int i = mnX; i <= mxX; i++) {
		for (int j = mnY; j <= mxY; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;

int r, c;
char arr[105][105];

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		scanf("%s", &arr[i]);
	}
	int cnt = 1;
	//우상단
	for (int i = r; i < 2 * r; i++) {
		for (int j = 0; j < c; j++)
			arr[i][j] = arr[r - cnt][j];
		cnt++;
	}

	//좌하단
	for (int i = 0; i < 2 * r; i++) {
		cnt = 1;
		for (int j = c; j < 2 * c; j++) {
			arr[i][j] = arr[i][c - cnt];
			cnt++;
		}
	}

	int a, b;
	cin >> a >> b;
	if (arr[a - 1][b - 1] == '.')arr[a - 1][b - 1] = '#';
	else arr[a - 1][b - 1] = '.';

	for (int i = 0; i < 2 * r; i++) {
		for (int j = 0; j < 2 * c; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <string.h>
#include <limits.h>
#include <math.h>
using namespace std;
int r, c, cou;
char arr[25][25];
int check[26], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int count) {
	check[arr[x][y] - 'A'] = 1;
	cou = max(cou, count);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!check[arr[nx][ny] - 'A'] && -1 < nx&&nx < r&&-1 < ny&&ny < c) {
			check[arr[nx][ny]-'A'] = 1;
			dfs(nx, ny, count + 1);
			check[arr[nx][ny]-'A'] = 0;
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)scanf("%s", &arr[i]);
	dfs(0, 0, 1);
	cout << cou << endl;
	return 0;
}
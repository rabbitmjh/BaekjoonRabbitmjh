#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <functional>
#include <vector>
#include <utility>
#include <string>
#include <math.h>
using namespace std;

int n, m, arr[101][101], arr1[101][101], r, f;
int dx[4] = { 0,0,1,-1 },dy[4] = { 1,-1,0,0 };
int disc[101][101];
bool chk(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
bool existCheese() {
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ret += arr[i][j];
	if (ret)f = ret;
	return ret;
}
void bfs() {
	memset(disc, 0, sizeof(disc));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		disc[i][0] = true;
		disc[i][m - 1] = true;
		q.push({ i,0 });
		q.push({ i,m - 1 });
	}
	for (int i = 0; i < m; i++) {
		disc[0][i] = true;
		disc[n - 1][i] = true;
		if (i)
			q.push({ 0,i });
		if (i != m - 1)
			q.push({ n - 1,i });
	}
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(nx, ny)) {
				if (!arr[nx][ny] && !disc[nx][ny]) {
					q.push({ nx,ny });
					disc[nx][ny] = true;
				}
				else if (arr[nx][ny]) arr1[nx][ny] = 1;
			}
		}
	}
}
void nextday() {
	bfs();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] &= (arr1[i][j] ^ 1);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	while (existCheese()) {
		r++;
		nextday();
	}
	printf("%d\n%d\n", r, f);
	return 0;
}
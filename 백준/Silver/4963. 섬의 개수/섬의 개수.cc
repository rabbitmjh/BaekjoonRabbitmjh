#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int>>q;
int w, h, sum;
int check[55][55];
int arr[55][55];
int dx[8] = { 1,-1,0,0,1,-1,1,-1 }, dy[8] = { 0,0,1,-1,1,-1,-1,1 };
void bfs(int x, int y) {
	q.push({ x,y });
	check[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx <= 50 && 1 <= ny <= 50 && check[nx][ny] == 0 && arr[nx][ny] == 1) {
				q.push({ nx,ny });
				check[nx][ny] = 1;
			}
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 || h == 0)return 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (check[i][j] == 0 && arr[i][j] == 1) {
					bfs(i, j);
					sum++;
				}
			}
		}
		printf("%d\n", sum);
		for (int i = 1; i <= h; i++) {
			memset(arr[i], 0, sizeof(arr[i]));
			memset(check[i], 0, sizeof(check[i]));
		}
		while (!q.empty())q.pop();
		sum = 0;
	}
	return 0;
}

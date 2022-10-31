#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
using namespace std;

char arr[105][105];
queue <pair<int, int>> q;
int n, sum, m, check[105][105], white, blue;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void bfs(char team) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		sum++;
		check[x][y] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (-1 < nx && nx < m && -1 < ny && ny < n && team == arr[nx][ny] && !check[nx][ny]) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%s", &arr[i]);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			sum = 0;
			if (!check[i][j]) {
				q.push({ i,j });
				bfs(arr[i][j]);
				if (arr[i][j] == 'W') white += sum*sum;
				else  blue += sum*sum;
			}
		}
	printf("%d %d\n", white, blue);
}
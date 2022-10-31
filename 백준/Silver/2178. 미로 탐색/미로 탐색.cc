#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int n, m;
int arr[105][105];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x,y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 1) {
				q.push({ nx, ny });
				arr[nx][ny] = arr[x][y] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	arr[0][0] = 1;
	bfs(0, 0);

	printf("%d\n", arr[n - 1][m - 1]);

	return 0;
}

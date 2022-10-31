#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;

char arr[55][55];
int check[55][55];
int n, m, sum;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void bfs(int i,int j,int time) {
	queue <pair<pair<int, int>,int>> q;
	q.push({ {i,j},time });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int nt = q.front().second;
		q.pop();
		sum = max(sum, nt);
		check[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (-1 < nx&&nx < n&&-1 < ny&&ny < m&&arr[nx][ny] == 'L'&&!check[nx][ny]) {
				q.push({ {nx,ny},nt + 1 });
				check[nx][ny] = 1;
			}
		}
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
			scanf("%s", &arr[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				bfs(i, j, 0);
				memset(check, 0, sizeof(check));
			}
		}
	}
	printf("%d", sum);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <queue>
using namespace std;
typedef pair<int, int> p;
typedef pair<p, int> pp;

int arr[105][105];
int check[105][105];
int n, m, sum=INT_MAX;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

queue<p> bridge;

void bfs(int i, int j, int count) {
	queue<p> q;
	q.push({ i,j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		check[x][y] = 1;
		arr[x][y] = count;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (-1 < nx&&nx < n && -1 < ny&&ny < n && !check[nx][ny] && arr[nx][ny]) {
				check[nx][ny] = 1;
				arr[nx][ny] = count;
				q.push({ nx,ny });
			}
		}
	}
}

void bfs_bridge(int k) {
	while (!bridge.empty()) {
		int x = bridge.front().first;
		int y = bridge.front().second;
		int len = check[x][y];
		bridge.pop();
		if (arr[x][y] > 0 && arr[x][y] != k) {
			sum = min(len - 1, sum);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (-1 < nx&&nx < n && -1 < ny&&ny < n &&!check[nx][ny]) {
				check[nx][ny] = len + 1;
				bridge.push({nx,ny});
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	int cou = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && !check[i][j]) {
				bfs(i, j, cou);
				cou++;
			}
		}
	//여기까진 대륙 넘버링

	for (int k = 1; k <= cou; k++) {//k는 대륙순서
		memset(check, 0, sizeof(check));
		while (!bridge.empty())bridge.pop();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == k) {
					check[i][j] = 1;
					for (int l = 0; l < 4; l++) {
						int nx = i + dx[l];
						int ny = j + dy[l];
						if (-1 < nx&&nx < n && -1 < ny&&ny < n&&!check[nx][ny]&&!arr[nx][ny]) {
							check[nx][ny] = 1;
							bridge.push({ nx,ny });
						}
					}
				}

			}
		}
		bfs_bridge(k);
	}
	printf("%d", sum);
	return 0;
}
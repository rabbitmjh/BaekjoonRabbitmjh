#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;

int arr[305][305],arr1[305][305];
int check[305][305];
int n, m, sum;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
	queue < pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		check[x][y] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx&&nx < n && 0 < ny&&ny < m&&!check[nx][ny] && arr[nx][ny]) {
				q.push({ nx,ny });
				check[nx][ny] = 1;
			}
		}
	}


}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int year = 0;
	while (1) {
		bool che = false;
		sum = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				int count = 0;
				if (arr[i][j]>0) {
					if (!arr[i - 1][j])count++;
					if (!arr[i + 1][j])count++;
					if (!arr[i][j - 1])count++;
					if (!arr[i][j + 1])count++;
					arr1[i][j] = count;
				}
			}
		}
		year++;
		for (int i = 1; i < n; i++) 
			for (int j = 1; j < m; j++) {
				arr[i][j] -= arr1[i][j];
				if (arr[i][j] < 0)arr[i][j] = 0;
			}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (arr[i][j]>0 && !check[i][j]) {
					bfs(i, j);
					che = true;
					sum++;
				}
			}
		}

		memset(check, 0, sizeof(check));
		if (!che) {
			printf("0");
			return 0;
		}
		if (sum > 1) {
			printf("%d", year);
			return 0;
		}
	}
	return 0;
}
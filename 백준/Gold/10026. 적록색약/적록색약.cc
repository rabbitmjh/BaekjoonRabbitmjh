#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
int n, sum,m;
string s;
char arr[105][105],c,arr1[105][105];
int check[105][105];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int> > q;
int bfs(int x, int y) {
	q.push({ x,y });
	check[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx < n && 0 <= ny < n && arr[nx][ny] == arr[x][y] && check[nx][ny] == 0) {
				q.push({ nx, ny });
				check[nx][ny] = 1;
			}
		}
	}
	return 0;
}
int bfs1(int x, int y) {
	q.push({ x,y });
	check[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx < n && 0 <= ny < n && arr1[nx][ny] == arr1[x][y] && check[nx][ny] == 0) {
				q.push({ nx, ny });
				check[nx][ny] = 1;
			}
		}
	}
	return 0;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
			arr1[i][j] = s[j];
			if (arr1[i][j] == 'G')arr1[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				bfs(i, j);
				sum++;
			}
		}
	}
	printf("%d\n", sum);
	sum = 0;
	for (int i = 0; i < n; i++) {
		memset(check[i], 0, sizeof(check[i]));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				bfs1(i, j);
				sum++;
			}
		}
	}
	printf("%d\n", sum);

	return 0;
}

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int tom[1005][1005];
int check[1005][1005];
int n, m, n1, n2, n3;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
queue <pair<int, int>> q;
void bfs(int y, int x) {
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && tom[ny][nx] == 0 && check[ny][nx] == 0) {
				q.push({ ny, nx });
				check[ny][nx] = 1+check[y][x];
				tom[ny][nx] = 1;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tom[i][j]);
			if (tom[i][j] == -1)n1++;
			else if (tom[i][j] == 0)n2++;
			else if (tom[i][j] == 1) {
				n3++;
				q.push({ i, j });
			}
		}
	}
	if (n2 == 0) {
		printf("0");
		return 0;
	}
	int x = q.front().first;
	int y = q.front().second;
	bfs(x, y);
	int big = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] > big)big = check[i][j];
			if (tom[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", big);
	return 0;
}
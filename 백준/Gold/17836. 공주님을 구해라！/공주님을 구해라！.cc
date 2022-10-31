#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
int arr[105][105], vis[105][105];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
vector <int> v;
int n, m, t;
int gx, gy, getG=1000000;

int bfs(int cnt) {
	queue<pp>q;
	q.push({ cnt, {1, 1} });
	vis[1][1] = 1;
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cnt = q.front().first;
		q.pop();

		if (arr[x][y] == 2)getG = cnt;
		if (x == n && y == m)return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx && nx <= n && 0 < ny && ny <= m && !vis[nx][ny] && arr[nx][ny] != 1) {
				q.push({ cnt + 1,{nx,ny} });
				vis[nx][ny] = 1;
			}
		}
	}
	return 1000000;
}

int main() {

	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				gx = i;
				gy = j;
			}
		}

	int justGo = bfs(0);

	int thr = n - gx + m - gy;
	int gram = getG + thr;

	int ans = min(justGo, gram);
	if (getG == 1000000)ans = justGo;
	if (ans > t)printf("Fail");
	else printf("%d\n", ans);

	return 0;
}
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;

char arr[1005][1005];
int vis[1005][1005], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int area, per, n;
void bfs(int i,int j) {
	int cnt1 = 0, cnt2 = 0;
	queue <p> q;
	q.push({ i,j });
	vis[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		cnt1++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx&&nx <= n && 0 <= ny&&ny <= n&&arr[nx][ny] == '#'&&!vis[nx][ny]) {
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
			if (!vis[nx][ny])cnt2++;
		}
	}
	if (area < cnt1) {
		area = cnt1;
		per = cnt2;
	}
	else if (area == cnt1)
		per = cnt2;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		scanf("%s", &arr[i]);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (arr[i][j] == '#'&&!vis[i][j])
				bfs(i, j);

	printf("%d %d\n", area, per);
	return 0;
}
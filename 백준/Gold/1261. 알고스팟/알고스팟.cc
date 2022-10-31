#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
int n, m, t;
int arr[105][105], dist[105][105], vis[105][105];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void dijikstra(int n,int m) {
	dist[1][1] = 0;
	priority_queue<pp,vector<pp>,greater<pp>> pq;
	pq.push({ 0,{1,1} });
	while (!pq.empty()) {
		int wall = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (dist[x][y] < wall)continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx&&nx <= m && 0 < ny&&ny <= n) {
				if (dist[nx][ny] > wall + arr[nx][ny]) {
					dist[nx][ny] = wall + arr[nx][ny];
					pq.push({ dist[nx][ny],{nx,ny} });
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%1d", &arr[i][j]),dist[i][j]=INT_MAX;

	dijikstra(n, m);
	printf("%d", dist[m][n]);
	return 0;
}

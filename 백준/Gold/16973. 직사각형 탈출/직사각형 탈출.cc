#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;

int n, m, H, W, Sr, Sc, Fr, Fc, sum = -1;
int v[1005][1005], vis[1005][1005];
queue <pp> q;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void bfs() {
	q.push({ 0,{ Sr,Sc } });
	vis[Sr][Sc] = 1;
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cost = q.front().first;
		q.pop();
		if (x == Fr && y == Fc) {
			sum = cost;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx&&nx <= n && 1 <= ny&&ny <= m&&!vis[nx][ny] && !v[nx][ny] && nx + H - 1 <= n&&ny + W - 1 <= m) {
				bool check = true;
				for (int j = nx; j <= H + nx - 1; j++) {
					if (j == nx || j == H + nx - 1) {
						for (int k = ny; k <= W + ny - 1; k++) {
							if (v[j][k]) {
								check = false;
								break;
							}
						}
					}
					else {
						if (v[j][ny] || v[j][ny + W - 1]) {
							check = false;
							break;
						}
					}
				}
				if (check) {
					q.push({ cost + 1,{nx,ny} });
					vis[nx][ny] = 1;
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int a;
			scanf("%d", &a);
			v[i][j] = a;
		}
	scanf("%d %d %d %d %d %d", &H, &W, &Sr, &Sc, &Fr, &Fc);
	bfs();
	printf("%d\n", sum);
	return 0;
}
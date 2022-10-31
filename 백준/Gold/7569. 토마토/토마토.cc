#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p>pp;
typedef pair<p, p> ppp;

vector <pp> v;
int n, m, h;
int vis[105][105][105];
int arr[105][105][105];
int cnt[105][105][105];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, dz[3] = {0, 1,-1};

void bfs(int z,int x,int y) {
	vis[z][x][y] = 1;
	cnt[z][x][y] = 0;
	queue <ppp> q;
	q.push({ {z,x}, {y,0} });
	while (!q.empty()) {
		int z = q.front().first.first;
		int x = q.front().first.second;
		int y = q.front().second.first;
		int cost = q.front().second.second;
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i > 0) {
				int nz = z + dz[i]; int nx = x; int ny = y;
				if (1 <= nz&&nz <= h && 1 <= nx&&nx <= m && 1 <= ny&&ny <= n&&arr[nz][nx][ny] == 1 && vis[nz][nx][ny] == 1 && cnt[nz][nx][ny] > cost + 1) {
					cnt[nz][nx][ny] = min(cnt[nz][nx][ny], cost + 1);
					q.push({ { nz,nx },{ ny,cnt[nz][nx][ny] } });
				}
				else if (1 <= nz&&nz <= h && 1 <= nx&&nx <= m && 1 <= ny&&ny <= n&&arr[nz][nx][ny]==0 && !vis[nz][nx][ny]) {
					arr[nz][nx][ny] = 1;
					vis[nz][nx][ny] = 1;
					if (cnt[nz][nx][ny] > 0) {
						cnt[nz][nx][ny] = min(cnt[nz][nx][ny], cost + 1);
						q.push({ { nz,nx },{ ny,cnt[nz][nx][ny] } });
					}
					else {
						cnt[nz][nx][ny] = cost + 1;
						q.push({ { nz,nx },{ ny,cnt[nz][nx][ny] } });
					}
				}
			}
			else {
				for (int j = 0; j < 4; j++) {
					int nz = z + dz[i];int nx = x + dx[j];int ny = y + dy[j];
					if (1 <= nz&&nz <= h && 1 <= nx&&nx <= m && 1 <= ny&&ny <= n&&arr[nz][nx][ny] == 1 && vis[nz][nx][ny] == 1 && cnt[nz][nx][ny] > cost + 1) {
						cnt[nz][nx][ny] = min(cnt[nz][nx][ny], cost + 1);
						q.push({ { nz,nx },{ ny,cnt[nz][nx][ny] } });
					}
					else if (1 <= nz&&nz <= h && 1 <= nx&&nx <= m && 1 <= ny&&ny <= n&&arr[nz][nx][ny] == 0 && !vis[nz][nx][ny]) {
						arr[nz][nx][ny] = 1;
						vis[nz][nx][ny] = 1;
						if (cnt[nz][nx][ny] > 0) {
							cnt[nz][nx][ny] = min(cnt[nz][nx][ny], cost + 1);
							q.push({ { nz,nx },{ ny,cnt[nz][nx][ny] } });
						}
						else {
							cnt[nz][nx][ny] = cost + 1;
							q.push({ { nz,nx },{ ny,cnt[nz][nx][ny] } });
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> m >> h;
	int w = 0;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= n; k++) {
				scanf("%d", &arr[i][j][k]);
				if (arr[i][j][k] == 1) {
					w++;
					v.push_back({ i,{j,k} });
				}
			}
	for (int i = 0; i < v.size(); i++) {
		bfs(v[i].first, v[i].second.first, v[i].second.second);
	}

	int mx = 0;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= n; k++) {
				mx = max(mx, cnt[i][j][k]);
				if (arr[i][j][k] == 0) {
					printf("-1\n");
					return 0;
				}
			}
	printf("%d", mx);
	return 0;
}
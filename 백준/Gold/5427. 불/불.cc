#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

queue<p> q;
vector<p> v;
int w, h, t;
int fire[1005][1005], sangkeun[1005][1005];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1, -1, 0,0 };
char map[1005][1005];

void fire_bfs() {//불을 따로 bfs 돌려줌
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)	{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w || map[nx][ny] == '#') 
				continue;

			if (fire[nx][ny] > fire[x][y] + 1) {//벽이 아니면 몇초에 그 위치에 도달하는지 저장
				fire[nx][ny] = fire[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int bfs(int i, int j) {
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) 
				return sangkeun[x][y];

			if (fire[nx][ny] > sangkeun[x][y] + 1 && map[nx][ny] != '#' && !sangkeun[nx][ny]) {
				sangkeun[nx][ny] = sangkeun[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return 0;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--)	{
		int x, y;
		cin >> w >> h;

		for (int i = 0; i < h; i++)	{
			fill(fire[i], fire[i] + w, 1000000);//불이 최대한 빨리 도착하도록 저장하기 위해
			fill(sangkeun[i], sangkeun[i] + w, 0);
			fill(map[i], map[i] + w, '\0');
		}
		v.clear();
		while (!q.empty()) q.pop();

		for (int i = 0; i < h; i++)	{
			string s; cin >> s;
			for (int j = 0; j < w; j++)	{
				map[i][j] = s[j];
				if (map[i][j] == '*') v.push_back({ i,j });
				else if (map[i][j] == '@') {
					x = i;
					y = j;
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			fire[v[i].first][v[i].second] = 1;
			q.push({ v[i].first, v[i].second });
		}
		fire_bfs();

		sangkeun[x][y] = 1;
		int ans = bfs(x, y);

		if (ans != 0) cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
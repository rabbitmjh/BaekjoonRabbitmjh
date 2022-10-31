#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int r1, c1, r2, c2, vis[10][10];
int dx[8] = { 3,2,-2,-3,-3,-2,2,3 }, dy[8] = { 2,3,3,2,-2,-3,-3,-2 };
vector <int> v;

int bfs(int x, int y) {
	queue <pp> q;
	q.push({ 0,{ x,y } });
	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		vis[x][y] = 1;
		if (r2 == x && c2 == y) {
			return cnt;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx <= 9 && 0 <= ny && ny <= 8 && !vis[nx][ny]) {
				if (i == 0) {
					if (r2 == x + 1 && c2 == y)continue;
					if (r2 == x + 2 && c2 == y + 1)continue;
				}
				else if (i == 1) {
					if (r2 == x && c2 == y + 1)continue;
					if (r2 == x + 1 && c2 == y + 2)continue;
				}
				else if (i == 2) {
					if (r2 == x && c2 == y + 1)continue;
					if (r2 == x - 1 && c2 == y + 2)continue;
				}
				else if (i == 3) {
					if (r2 == x - 1 && c2 == y)continue;
					if (r2 == x - 2 && c2 == y + 1)continue;
				}
				else if (i == 4) {
					if (r2 == x - 1 && c2 == y)continue;
					if (r2 == x - 2 && c2 == y - 1)continue;
				}
				else if (i == 5) {
					if (r2 == x && c2 == y - 1)continue;
					if (r2 == x - 1 && c2 == y - 2)continue;
				}
				else if (i == 6) {
					if (r2 == x && c2 == y - 1)continue;
					if (r2 == x + 1 && c2 == y - 2)continue;
				}
				else if (i == 7) {
					if (r2 == x + 1 && c2 == y)continue;
					if (r2 == x + 2 && c2 == y - 1)continue;
				}
				q.push({ cnt + 1,{ nx,ny } });
			}
		}
	}
	return -1;
}

int main() {
	FIO;
	cin >> r1 >> c1 >> r2 >> c2;
	
	cout << bfs(r1, c1);

	return 0;
}
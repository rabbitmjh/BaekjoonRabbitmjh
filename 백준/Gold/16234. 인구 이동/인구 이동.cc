#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, l, r, ans, arr[55][55], vis[55][55], last[55][55];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
p allySum[3050];

void bfs(int x, int y, int ally) {
	queue <p> q;
	q.push({ x,y });
	vis[x][y] = ally;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			int dif = abs(arr[xx][yy] - arr[nx][ny]);
			if (-1 < xx && xx < n && -1 < yy && yy < n)
				if (!vis[xx][yy] && l <= dif && dif <= r)
					q.push({ xx,yy }),vis[xx][yy]=ally;
			
		}
	}
}

int main() {
	FIO;
	cin >> n >> l >> r;
	for (int i = 0;i < n;i++) 
		for (int j = 0;j < n;j++)
			cin >> arr[i][j];

	if (n == 1) {
		cout << 0 << "\n";
		return 0;
	}

	while (1) {
		int cnt = 0;

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				last[i][j] = arr[i][j];
				if (!vis[i][j]) {
					cnt++;
					bfs(i, j, cnt);
				}
			}
		}

		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++) {
				allySum[vis[i][j]].first += arr[i][j];
				allySum[vis[i][j]].second++;
			}

		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				arr[i][j] = allySum[vis[i][j]].first / allySum[vis[i][j]].second;

		int chk = 0;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				if (last[i][j] != arr[i][j])
					chk++;

		if (!chk)break;
		ans++;

		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				vis[i][j] = 0;
		for (int i = 0;i < n * n;i++)
			allySum[i] = { 0,0 };
	}
	cout << ans;

	return 0;
}
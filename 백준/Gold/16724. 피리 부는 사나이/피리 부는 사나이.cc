#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, cnt, arr1[1005][1005], vis[1005][1005];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
char arr[1005][1005];

void dfs(int x, int y) {
	vis[x][y] = 1;

	int nx = x + dx[arr1[x][y]];
	int ny = y + dy[arr1[x][y]];

	if (vis[nx][ny] == 1)
		cnt++;
	if (!vis[nx][ny])
		dfs(nx, ny);
	vis[x][y] = 2;

	return;
}

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'D')
				arr1[i][j] = 0;
			else if (arr[i][j] == 'U')
				arr1[i][j] = 1;
			else if (arr[i][j] == 'R')
				arr1[i][j] = 2;
			else if (arr[i][j] == 'L')
				arr1[i][j] = 3;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j])
				dfs(i, j);

	cout << cnt;
	return 0;
}
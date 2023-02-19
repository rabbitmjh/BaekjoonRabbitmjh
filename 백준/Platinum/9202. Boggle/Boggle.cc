#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int dx[8] = { 0, 0, 1, -1, -1, -1, 1, 1 }, dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int w, b, vis[5][5], arr[5][5], ansNum, ansLen, idx, cnt, boogle[300005];
vector <string> v;

void dfs(int widx, int i, int x, int y) {
	if (v[widx].size() == i && !boogle[widx]) {
		boogle[widx] = 1;
		if (i == 3 || i == 4)ansNum++;
		else if (i == 5)ansNum += 2;
		else if (i == 6)ansNum += 3;
		else if (i == 7) ansNum += 5;
		else if (i == 8) ansNum += 11;
		if (i > ansLen) {
			ansLen = i;
			idx = widx;
		}
		cnt++;
	}
	else {
		for (int j = 0; j < 8; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (-1 < nx && nx < 4 && -1 < ny && ny < 4 && !vis[nx][ny] && arr[nx][ny] == v[widx][i]) {
				vis[nx][ny] = 1;
				dfs(widx, i + 1, nx, ny);
				vis[nx][ny] = 0;
			}
		}
	}
	vis[x][y] = 0;
}

int main() {
	FIO;
	cin >> w;
	for (int i = 0; i < w; i++) {
		string s; cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());

	cin >> b;
	while(b--) {
		for (int i = 0; i < 4; i++) {
			string s; cin >> s;
			for (int j = 0; j < 4; j++) {
				arr[i][j] = s[j];
			}
		}
		memset(boogle, 0, sizeof(boogle));
		ansNum = 0, ansLen = -1, idx = 0, cnt = 0;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (arr[j][k] == v[i][0] && !boogle[i]) {
						vis[j][k] = 1;
						dfs(i, 1, j, k);
					}
				}
			}
		}

		cout << ansNum << " " << v[idx] << " " << cnt << "\n";
	}
	return 0;
}
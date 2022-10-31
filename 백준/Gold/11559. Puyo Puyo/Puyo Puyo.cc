#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans, chain, vis[15][15], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
char puyo[15][15];
vector <p> v;

void check(int a, int b) {
	queue <p> q;
	q.push({ a,b });
	vis[a][b] = 1;
	char color = puyo[a][b];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		v.push_back({ x,y });
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 12 && !vis[nx][ny] && puyo[nx][ny] == color) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void fall() {
	for (int i = 0; i < 6; i++) {
		int to = 11;
		for (int j = 11; j >= 0; j--) {
			if (puyo[j][i] == '.')
				continue;
			if (to != j)
				swap(puyo[to][i], puyo[j][i]);
			to--;
		}
	}
}

int main() {
	FIO;
	for (int i = 0; i < 12; i++)
		cin >> puyo[i];

	while (1) {
		for (int i = 0; i < 12; i++)//4개 이상 모여있는지 확인
			for (int j = 0; j < 6; j++)
				if (puyo[i][j] != '.' && !vis[i][j]) {
					check(i, j);

					if (v.size() >= 4) {
						for (int i = 0; i < v.size(); i++)
							vis[v[i].first][v[i].second] = 2;
						chain++;
					}
					v.clear();
				}

		if (!chain) {//없앨 수 있는지 확인
			cout << ans;
			break;
		}
		ans++;

		for (int i = 0; i < 12; i++)//없앰
			for (int j = 0; j < 6; j++)
				if (vis[i][j] == 2)
					puyo[i][j] = '.';

		fall();//빈 공간 채우기
		chain = 0;
		memset(vis, 0, sizeof(vis));
	}

	return 0;
}
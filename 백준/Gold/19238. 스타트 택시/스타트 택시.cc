#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, f, arr[25][25], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
p taxi;
vector <p> des;

p findPassenger(int a, int b) {
	queue <pp> q;
	int fvis[25][25] = { 0 };
	vector <pp> v;
	q.push({ 0,{ a,b } });
	fvis[a][b] = 1;

	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (f - cnt < 0)
			continue;

		if (arr[x][y] > 0) 
			v.push_back({ cnt,{x,y} });

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 < nx && nx <= n && 0 < ny && ny <= n && !fvis[nx][ny] && arr[nx][ny] != -1) {
				q.push({ cnt + 1,{nx,ny} });
				fvis[nx][ny] = 1;
			}
		}
	}
	if (!v.empty()) {
		sort(v.begin(), v.end());
		f -= v.front().first;
		taxi = { v.front().second.first,v.front().second.second };
		return { v.front().second.first,v.front().second.second };
	}
	return { -1,-1 };
}

bool destination(int a, int b) {
	queue <pp> q;
	int fvis[25][25] = { 0 };
	q.push({ 0,{ taxi.first,taxi.second } });
	fvis[taxi.first][taxi.second] = 1;

	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		fvis[x][y] = 1;

		if (f - cnt < 0)
			continue;

		if (x == a && y == b) {
			taxi = { x,y };
			f += cnt;
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 < nx && nx <= n && 0 < ny && ny <= n && !fvis[nx][ny] && arr[nx][ny] != -1) {
				q.push({ cnt + 1,{nx,ny} });
				fvis[nx][ny] = 1;
			}
		}
	}
	return false;
}

int main() {
	FIO;
	cin >> n >> m >> f;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				arr[i][j] = -1;
		}

	cin >> taxi.first >> taxi.second;
	des.push_back({ -1,-1 });
	for (int i = 1; i <= m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arr[x1][y1] = i;
		des.push_back({ x2,y2 });
	}

	while (1) {
		p go = findPassenger(taxi.first, taxi.second);
		if (go.first == -1 && go.second == -1) {
			if (m > 0) {
				cout << -1;
				return 0;
			}
			else break;
		}

		int w = arr[go.first][go.second];
		if (f < 0 || !destination(des[w].first, des[w].second)) {
			cout << -1;
			return 0;
		}
		arr[go.first][go.second] = 0;
		m--;
	}

	cout << f;
	return 0;
}
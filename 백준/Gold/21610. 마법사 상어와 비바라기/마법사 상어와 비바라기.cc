#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans, arr[55][55], chk[55][55], f;
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 }, dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };//방향
int cx[4] = { 0,0,-1,-1 }, cy[4] = { 0,1,0,1 };//구름
int iy[4] = { -1,1,1,-1 }, ix[4] = { 1,1,-1,-1 };//대각선
vector <p> v;
queue <p> q;

void move(int d, int s) {//이동 후 구름이 있던 곳 저장
	s %= n;
	
	if (!f) {
		for (int i = 0; i < 4; i++) {//처음 구름4칸 n,1/n,2/n-1,1/n-1,2
			int nx = cx[i] + n;
			int ny = cy[i] + 1;

			nx += dx[d] * s;
			ny += dy[d] * s;

			if (nx < 1)
				nx += n;
			else if (nx > n)
				nx -= n;
			if (ny < 1)
				ny += n;
			else if (ny > n)
				ny -= n;

			chk[nx][ny] = 1;//구름중복생성방지
			v.push_back({ nx,ny });//물이 증가한 칸 저장 magic에 필요
			f = 1;
		}
	}
	while (!q.empty()) {//이미 있는 구름 이동
		int x = q.front().first, y = q.front().second;
		q.pop();

		x += dx[d] * s, y += dy[d] * s;
		if (x < 1)x += n;
		else if (x > n)x -= n;
		if (y < 1)y += n;
		else if (y > n)y -= n;

		if (chk[x][y])continue;//이미 구름이 이동했던 곳이면 스킵
		chk[x][y] = 1;
		v.push_back({ x,y });
	}
	return;
}
void magic() {//물복사버그마법
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		for (int j = 0; j < 4; j++) {
			int nx = x + ix[j], ny = y + iy[j];
			if (nx<1 || nx>n || ny < 1 || ny>n)//경계 넘어가면 스킵
				continue;
			if (arr[nx][ny])//대각선방향에 물이 있으면 ++
				arr[x][y]++;
		}
	}
	return;
}

int main() {
	FIO;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	while (m--) {
		int d, s; cin >> d >> s;
		move(d, s);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] += chk[i][j];

		magic();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > 1 && !chk[i][j]) {//구름이 사라진칸이 아니고 2이상이면 구름생성
					q.push({ i,j });
					arr[i][j] -= 2;
				}
			}
		}
		memset(chk, 0, sizeof(chk));
		v.clear();
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += arr[i][j];

	cout << ans;
	return 0;
}
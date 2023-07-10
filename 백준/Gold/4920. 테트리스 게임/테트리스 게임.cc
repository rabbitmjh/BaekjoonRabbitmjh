#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[105][105], ans = -1e9, sum, cnt = 1;
bool flag = true;

int dlx1[4] = { 0,1,2,3 }, dly1[4] = { 0,0,0,0 };//ㅣ모양
int dlx2[4] = { 0,0,0,0 }, dly2[4] = { 0,1,2,3 };//ㅣ모양90도

int dzx1[4] = { 0,0,1,1 }, dzy1[4] = { 0,1,1,2 };//z모양
int dzx2[4] = { 0,1,1,2 }, dzy2[4] = { 0,0,-1,-1 };//z모양90도

int drx1[4] = { 0,0,0,1 }, dry1[4] = { 0,1,2,2 };//ㄱ모양
int drx2[4] = { 0,1,2,2 }, dry2[4] = { 0,0,0,-1 };//ㄱ모양90도
int drx3[4] = { 0,0,0,-1 }, dry3[4] = { 0,-1,-2,-2 };//ㄱ모양180도
int drx4[4] = { 0,-1,-2,-2 }, dry4[4] = { 0,0,0,1 };//ㄱ모양270도

int dnx1[4] = { 0,0,1,0 }, dny1[4] = { 0,1,1,2 };//ㅜ모양
int dnx2[4] = { 0,1,1,2 }, dny2[4] = { 0,0,-1,0 };//ㅜ모양90도
int dnx3[4] = { 0,0,-1,0 }, dny3[4] = { 0,-1,-1,-2 };//ㅜ모양180도
int dnx4[4] = { 0,-1,-1,-2 }, dny4[4] = { 0,0,1,0 };//ㅜ모양270도

int dx[4] = { 0,0,1,1 }, dy[4] = { 0,1,0,1 };//ㅁ모양

bool check(int x, int y) {
	if (0 < x && x <= n && 0 < y && y <= n)
		return true;
	else return false;
}
void init() {
	flag = true;
	sum = 0;
}
void block(int x[], int y[], int i, int j) {
	init();
	sum = arr[i][j];
	for (int k = 1;k < 4;k++) {
		int nx = i + x[k];
		int ny = j + y[k];
		flag = check(nx, ny);

		if (!flag)
			return;
		sum += arr[nx][ny];
	}
	ans = max(ans, sum);
}

int main() {
	FIO;
	while (1) {
		if (cnt == 1)
			cin >> n;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				cin >> arr[i][j];

		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				block(dlx1, dly1, i, j);
				block(dlx2, dly2, i, j);

				block(dzx1, dzy1, i, j);
				block(dzx2, dzy2, i, j);

				block(drx1, dry1, i, j);
				block(drx2, dry2, i, j);
				block(drx3, dry3, i, j);
				block(drx4, dry4, i, j);

				block(dnx1, dny1, i, j);
				block(dnx2, dny2, i, j);
				block(dnx3, dny3, i, j);
				block(dnx4, dny4, i, j);

				block(dx, dy, i, j);
			}
		}
		cout << cnt << ". " << ans << "\n";
		ans = -1e9;
		cnt++;
		cin >> n;
		if (!n)break;
	}
	return 0;
}
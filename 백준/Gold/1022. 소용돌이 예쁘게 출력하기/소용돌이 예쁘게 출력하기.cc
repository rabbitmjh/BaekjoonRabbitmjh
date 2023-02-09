#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int r1, c1, r2, c2, arr[55][10], dir = 3, cnt;
int r, c, x, y, n = 1, swirl = 1;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };//반시계방향

bool check() {//4 모서리가 차있는지
	if (arr[0][0] && arr[0][c] && arr[r][0] && arr[r][c])
		return false;
	else return true;
}

int main() {
	FIO;

	cin >> r1 >> c1 >> r2 >> c2;
	r = r2 - r1;
	c = c2 - c1;

	while (check()) {
		if (0 <= x - r1 && x - r1 <= r && 0 <= y - c1 && y - c1 <= c)
			arr[x - r1][y - c1] = n;
		n++;
		cnt++;
		x += dx[dir];
		y += dy[dir];

		if (cnt == swirl) {
			cnt = 0;
			dir++;
			if (dir > 3)dir = 0;
			if (dir % 2 == 1)
				swirl++;
		}
	}

	int ans = 0;
	while (n) {
		n /= 10;
		ans++;
	}

	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++)
			cout << setw(ans) << arr[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
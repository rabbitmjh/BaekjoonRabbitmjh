#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

int n, m;
int dx[4] = { 0,1,-1,0 }, dy[4] = { -1,0,0,1 };
int Wvis[1505][1505], Svis[1505][1505];
int L[2][2], cnt = 0;
queue <p> arrW, arrW1, arrS, arrS1;
char arr[1505][1505];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'L') {
				L[cnt][0] = i;
				L[cnt++][1] = j;
				arr[i][j] = '.';
			}
			if (arr[i][j] == '.') {
				arrW.push({ i,j });
				Wvis[i][j] = 1;
			}
		}
	}

	arrS.push({ L[0][0],L[0][1] });
	Svis[L[0][0]][L[0][1]] = 1;

	int ans = 0;
	for (ans = 0; !Svis[L[1][0]][L[1][1]]; ans++) {
		for (; !arrW.empty(); arrW.pop()) arrW1.push(arrW.front());
		for (; !arrS.empty(); arrS.pop()) arrS1.push(arrS.front());

		for (; !arrW1.empty(); arrW1.pop()) {
			int y = arrW1.front().first, x = arrW1.front().second;
			arr[y][x] = '.';
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m || Wvis[ny][nx]) continue;
				Wvis[ny][nx] = 1;
				arrW.push({ ny, nx });
			}
		}

		for (; !arrS1.empty(); arrS1.pop()) {
			int y = arrS1.front().first, x = arrS1.front().second;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m || Svis[ny][nx]) continue;
				Svis[ny][nx] = 1;
				if (arr[ny][nx] == '.')    arrS1.push({ ny, nx });
				else if (arr[ny][nx] == 'X') arrS.push({ ny, nx });
			}
		}
	}
	printf("%d\n", ans - 1);
	return 0;
}
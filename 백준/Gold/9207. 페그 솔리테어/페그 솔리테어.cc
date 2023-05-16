#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, pin, minMove;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
char arr[10][10];

int count() {
	int cnt = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
			if (arr[i][j] == 'o')
				cnt++;

	return min(cnt, minMove);
}

void go() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 'o') {

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx > -1 && ny > -1 && nx < 9 && ny < 9 && arr[nx][ny] == 'o') {
						int jx = nx + dx[k];
						int jy = ny + dy[k];

						if (jx > -1 && jy > -1 && jx < 9 && jy < 9 && arr[jx][jy] == '.') {
							arr[jx][jy] = 'o';
							arr[nx][ny] = '.';
							arr[i][j] = '.';
							go();

							arr[jx][jy] = '.';
							arr[nx][ny] = 'o';
							arr[i][j] = 'o';
						}
					}
				}
			}
		}
	}

	minMove = count();
}

int main() {
	FIO;
	cin >> t;
	while (t--) {
		pin = 0;
		minMove = 9;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'o')
					pin++;
			}
		}
		go();
		cout << minMove << " " << pin - minMove << "\n";
	}
	return 0;
}
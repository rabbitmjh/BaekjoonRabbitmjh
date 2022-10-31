#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, arr[1005][1005], map[1005][1005];
int dx[3] = { 1,0,1 }, dy[3] = { 0,1,1 };

void go() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 3; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx <= n && ny <= m)
					map[nx][ny] = max(map[nx][ny], map[i][j] + arr[nx][ny]);
			}
		}
	}
}



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	map[1][1] = arr[1][1];
	go();
	cout << map[n][m];


	return 0;
}
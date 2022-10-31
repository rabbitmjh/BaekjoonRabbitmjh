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

int n, m, ans, high, arr[55][55];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };

void bfs(int num) {
	queue <p> q;
	q.push({ 0,0 });
	arr[0][0] = num;	
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx <= n + 1 && 0 <= ny && ny <= m + 1 && arr[nx][ny] < num) {
				arr[nx][ny] = num;
				q.push({ nx, ny });
			}
		}
	}
}



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = s[j - 1] - '0';
			high = max(high, arr[i][j]);
		}
	}
	for (int h = 1; h <= high; h++) {
		bfs(h);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] < h) {
					ans++;
					arr[i][j]++;
				}
			}
		}
	}
	cout << ans;


	return 0;
}
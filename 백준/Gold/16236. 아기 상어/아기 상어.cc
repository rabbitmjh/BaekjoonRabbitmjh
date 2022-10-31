#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
typedef pair <int, p> pp;
typedef pair <p, p> ppp;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, ans, s = 2, cnt, fx, fy;
int arr[25][25];
int vis[25][25];

ppp bfs() {
	memset(vis, 0, sizeof(vis));
	vector <pp> v;
	queue <pp> q;
	q.push({ 0,{fx,fy} });
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cur = q.front().first;
		q.pop();

		if (arr[x][y] && arr[x][y] < s)
			v.push_back({ cur,{x,y} });
		if (vis[x][y]) continue;
		vis[x][y] = 1;

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (-1 < nx&&nx < n&&-1 < ny&&ny < n && arr[nx][ny] <= s)
				q.push({ cur + 1,{nx,ny} });
		}
	}

	if (v.empty())return { {false,false},{false,false} };
	else {
		sort(v.begin(), v.end());
		int x = v.front().second.first;
		int y = v.front().second.second;
		return { {x,y},{v.front().first,arr[x][y]} };
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			
			if (arr[i][j] == 9) {
				fx = i;
				fy = j;
				arr[i][j] = 0;
			}
		}

	while (1) {
		ppp babyShark = bfs();
		if (babyShark.second.first == false)break;

		int x = babyShark.first.first;
		int y = babyShark.first.second;
		int dis = babyShark.second.first;
		int siz = babyShark.second.second;

		ans += dis;
		fx = x; fy = y;
		cnt++;
		arr[x][y] = 0;
		if (cnt == s) {
			s++;
			cnt = 0;
		}
	}

	printf("%d", ans);
	return 0;
}
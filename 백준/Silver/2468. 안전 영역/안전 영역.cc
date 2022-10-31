#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <functional>
using namespace std;

int n, sum,n1,n2,k;
int arr[105][105];
int check[105][105];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector <int> v,v1;

queue<pair<int, int> > q;
int bfs(int x, int y, int k) {
	sum = 1;
	q.push({ x,y });
	check[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] > k && check[nx][ny] == 0) {
				q.push({ nx, ny });
				check[nx][ny] = 1;
				sum++;
			}
		}
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &n1);
			if (n1 > n2)n2 = n1;
			arr[i][j] = n1;

		}
	}

	for (int k = 0; k <= n2; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > k && check[i][j] == 0) {
					bfs(i, j, k);
					v.push_back(sum);
				}
			}
		}
		v1.push_back(v.size());
		v.clear();
		memset(check, 0, sizeof(check));
	}
	sort(v1.begin(), v1.end(),greater <int>());
	printf("%d", v1.front());

	return 0;
}

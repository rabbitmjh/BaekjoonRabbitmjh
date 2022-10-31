#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n, sum,m,n1,n2,n3,n4,k,sum1;
int check[105][105];
int arr[105][105];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
queue<pair<int,int>> q;
vector<int> v;
int bfs(int x, int y) {
	q.push({ x,y });
	check[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0)continue;
			if (0 <= nx && nx < m && 0 <= ny && ny < n && arr[nx][ny] == 0 && check[nx][ny] == 0) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
		sum++;
	}
	return 0;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> n1 >> n2 >> n3 >> n4;
		for (int j= n1; j < n3; j++) {
			for (int l = n2; l < n4; l++) {
				arr[j][l] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && check[i][j] == 0) {
				bfs(i, j);
				v.push_back(sum);
				sum = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}

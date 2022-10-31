#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <limits.h>
#include <math.h>
#include <queue>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;

int n, m, check[30][30];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int arr[30][30];
vector <int> v;
queue <pair<int,int>> q;

void bfs(int x,int y) {
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		check[x][y] = 1, m++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (-1 < nx&&nx < n && -1 < ny&&ny < n )
				if (check[nx][ny] == 0 && arr[nx][ny] == 1) {
					q.push({ nx,ny });
					check[nx][ny] = 1;
				}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)scanf("%1d", &arr[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && arr[i][j]) {
				bfs(i, j);
				v.push_back(m);
				m = 0;
			}
		}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)printf("%d\n", v[i]);
	return 0;
}

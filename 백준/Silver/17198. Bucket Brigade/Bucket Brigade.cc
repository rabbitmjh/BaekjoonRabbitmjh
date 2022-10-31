#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
typedef pair <int, p> pp;
int check[11][11];

int main() {
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	char arr[11][11];
	p B, R, L;

	for (int i = 1; i <= 10; i++)
		scanf("%s", arr[i]);

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++) {
			if (arr[i][j] == 'B')B.first = i, B.second = j;
			else if (arr[i][j] == 'L')L.first = i, L.second = j;
		}

	queue <pp> q;
	q.push({ 0, { B.first,B.second } });
	check[B.first][B.second] = 1;
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cnt = q.front().first;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[nx][ny] == 'L') {
				printf("%d\n", cnt);
				return 0;
			}
			if (1 <= nx&&nx <= 10 && 1 <= ny&&ny <= 10 && arr[nx][ny] != 'R'&&!check[nx][ny]) {
				q.push({ cnt + 1,{nx,ny} });
				check[nx][ny] = 1;
			}
		}
	}

	return 0;
}
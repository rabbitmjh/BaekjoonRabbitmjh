#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
vector<vector<int>>v(105);
queue<int>q;

int n,t,arr[105];

void bfs() {
	while (!q.empty()) {
		int nx = q.front();
		q.pop();
		arr[nx] = 1;
		for (int i = 0; i < v[nx].size(); i++) {
			if (arr[v[nx][i]] == 0&&v[nx][i]!=1) {
				arr[v[nx][i]] = 1;
				q.push(v[nx][i]);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n,&t);
	for (int i = 0; i < t; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		if (x == 1)q.push(y);
		else if (y == 1)q.push(x);
	}
	bfs();
	int sum = 0;
	for (int i = 0; i < 105; i++)sum += arr[i];
	printf("%d", sum);
	return 0;
}
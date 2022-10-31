#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n, sum,m,n1,n2,e,w;
int check[105];
vector<vector<int>> v(105);
queue<int> q;

int bfs(int x, int y) {
	q.push(x);
	check[x] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i];
			if (check[next] == 0) {
				check[next] = 1+check[x];
				q.push(next);
			}
		}
	}
	return 0;
}

int main() {
	cin >> n;
	cin >> n1 >> n2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &e, &w);
		v[e].push_back(w);
		v[w].push_back(e);
	}
	bfs(n1, n2);
	if (check[n2] == 0) {
		printf("-1");
		return 0;
	}
	printf("%d", check[n2]-1);
	return 0;
}

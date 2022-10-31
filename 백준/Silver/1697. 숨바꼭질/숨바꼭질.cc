#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n, sum,m,k;
int check[100005];
int dx[3] = { 1,-1,n };
queue<int> q;
vector<int> v;
int bfs(int x) {
	q.push(x);
	check[x] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		dx[2] = x;
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			if (nx == k) {
				check[nx] = check[x];
				v.push_back(check[nx]);
				continue;
			}
			if (0 <= nx && nx <= 100000 && check[nx] == 0) {
				check[nx] = 1+check[x];
				q.push(nx);
			}
		}
	}
	return 0;
}

int main() {
	cin >> n >> k;
	if (n == k) {
		printf("0");
		return 0;
	}
	bfs(n);
	sort(v.begin(), v.end());
	printf("%d", v.front());
	return 0;
}

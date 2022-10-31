#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int n, sum, m, k, s, t;
int check[1005][1005];
int dx[2] = { 1,2 };
int dy[2] = { 0,3 };
queue<pair<int, int>> q;
vector<int> v;
int bfs(int s, int t) {
	q.push({ s,t });

	while (!q.empty()) {
		s = q.front().first;
		t = q.front().second;
		q.pop();
		dx[1] = s;
		for (int i = 0; i < 2; i++) {
			int ns = s + dx[i];
			int nt = t + dy[i];
			if (ns > nt)continue;

			if (check[ns][nt] == 0) {
				check[ns][nt] = 1 + check[s][t];
				if (ns == nt) {
					check[ns][nt] = 1 + check[s][t];
					return check[ns][nt];
				}
				q.push({ ns, nt });
			}
		}
	}
}


int main() {
	cin >> n;
	while (n--) {
		cin >> s >> t;
		printf("%d\n",bfs(s,t));

		memset(check, 0, sizeof(check));
		
		while (!q.empty()) {
			q.pop();
		}
	}
	return 0;
}

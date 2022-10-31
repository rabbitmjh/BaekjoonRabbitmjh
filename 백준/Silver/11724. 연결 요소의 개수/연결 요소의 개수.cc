#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, n1, n2, sum, ans;
int check1[1005];
vector<vector<int>>pq(1005);

void dfs(int x) {
	check1[x] = 1;
	for (int i = 0; i < pq[x].size(); i++) {
		int next = pq[x][i];
		if (check1[next] == 0) {
			dfs(next);
		}
	}
	sum++;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &n1, &n2);
		pq[n1].push_back(n2);
		pq[n2].push_back(n1);
	}
	int x=1;
	while (sum < n) {
		if (check1[x] == 0) {
			dfs(x);
			ans++;
		}
		x++;
	}
	printf("%d", ans);
	return 0;
}

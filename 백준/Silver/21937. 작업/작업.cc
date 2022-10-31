#include <iostream>
#include <vector>
using namespace std;
bool visited[100005];
vector<int> adj[100005];
int n, m, x;
int cnt = 0;
int dfs(int now) {
	visited[now] = 1;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (!visited[next]) {
			cnt++;
			dfs(next);
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	cin >> x;
	cout << dfs(x);
}
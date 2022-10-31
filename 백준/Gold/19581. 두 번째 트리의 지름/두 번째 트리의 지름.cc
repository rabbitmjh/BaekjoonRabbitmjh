#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, vis[100005], sum, ans, c, a, b;
vector <p> tree[100005];
queue <p> q;

void bfs(int num) {
	q.push({ num,0 });
	while (!q.empty()) {
		int next = q.front().first;
		int cnt = q.front().second;
		vis[next] = 1;
		q.pop();
		if (sum < cnt) {
			sum = cnt;
			if (!c)a = next;
			else if (c == 1) b = next;
		}

		for (int i = 0;i < tree[next].size();i++) {
			if (!vis[tree[next][i].first])
				q.push({ tree[next][i].first,cnt + tree[next][i].second });
		}
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y, cnt;
		cin >> x >> y >> cnt;
		tree[x].push_back({ y,cnt });
		tree[y].push_back({ x,cnt });
	}
	//트리의 지름을 먼저 구하고
	bfs(1);
	memset(vis, 0, sizeof(vis));
	sum = 0;
	c++;

	//지름 위치를 저장해
	bfs(a);
	memset(vis, 0, sizeof(vis));
	sum = 0;
	c++;

	//하나씩 제외해가면서 두 번째로 긴 지름을 구하면 끝
	vis[b] = 1;
	bfs(a);
	ans = sum;

	memset(vis, 0, sizeof(vis));

	vis[a] = 1;
	bfs(b);

	cout << max(ans, sum);

	return 0;
}
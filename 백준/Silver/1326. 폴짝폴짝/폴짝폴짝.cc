#include <iostream>	
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int n, a, b, count, cnt, swi;
int arr[10005], vis[10005];
queue <p> q;

void bfs() {
	while (!q.empty()) {
		if (q.front().first == b) {
			cnt = q.front().second;
			swi++;
			break;
		}
		int now = q.front().first;
		int jump = q.front().second;
		q.pop();

		for (int i = 1; now + (arr[now] * i) <= n; i++) {
			int next = now + arr[now] * i;
			if (!vis[next]) {
				vis[next] = 1;
				q.push({ next,jump + 1 });
			}
		}
		for (int i = 1; now - (arr[now] * i) >= 1; i++) {
			int next = now - arr[now] * i;
			if (!vis[next]) {
				vis[next] = 1;
				q.push({ next,jump + 1 });
			}
		}
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	cin >> a >> b;
	q.push({ a,0 });
	vis[a] = 1;
	bfs();
	if (!swi)printf("-1");
	else printf("%d", cnt);
	return 0;
}

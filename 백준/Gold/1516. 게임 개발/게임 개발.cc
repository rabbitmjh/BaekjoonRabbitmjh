#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>
#include <limits.h>
#include <math.h>
using namespace std;
queue <int> q;
int n, m, addnum;
vector <vector<int>> v(505);
int sum[505];
int arr[505]; int d[505];

void bfs() {
	for (int i = 1; i <= n; i++) {
		if (!d[i]) {
			q.push(i);
			sum[i] = arr[i];
		}
	}
	while (!q.empty()) {
		int next = q.front();
		q.pop();

		for (int i = 0; i < v[next].size(); i++) {
			sum[v[next][i]] = max(sum[v[next][i]], sum[next] + arr[v[next][i]]);
			--d[v[next][i]];
			if (!d[v[next][i]])q.push(v[next][i]);
		}
	}


}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int time, a = 0;
		cin >> time;
		arr[i] = time;
		while (1) {
			scanf("%d", &a);
			if (a == -1)break;
			v[a].push_back(i);
			d[i]++;
		}
	}
	bfs();
	for (int i = 1; i <= n; i++)
		printf("%d\n", sum[i]);
	

	return 0;
}
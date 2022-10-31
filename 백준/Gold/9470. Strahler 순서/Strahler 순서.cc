#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef long long ll;

int t, m, p, k, x, y, arr[1001], arr1[1001], arr2[1001], res;
vector<vector<int>> v;
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (arr2[here] > 0)arr1[here]++;
		res = max(arr1[here], res);
		for (auto there : v[here]) {
			if (arr1[there] < arr1[here]) {
				arr1[there] = arr1[here];
				arr2[there] = 0;
			}
			else if (arr1[there] == arr1[here])
				arr2[there]++;
			arr[there]--;
			if (!arr[there])
				q.push(there);
		}
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		v.clear();
		scanf("%d%d%d", &k, &m, &p);
		v.resize(m + 1);

		res = 0;
		for (int i = 0; i < p; i++) {
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			arr[y]++;
		}

		for (int i = 1; i <= m; i++) {
			if (!arr[i]) {
				arr1[i] = 1;
				q.push(i);
			}
		}
		bfs();

		printf("%d %d\n", k, res);
		memset(arr, 0, sizeof(arr));
		memset(arr2, 0, sizeof(arr2));
		memset(arr1, 0, sizeof(arr1));
	}
	return 0;
}
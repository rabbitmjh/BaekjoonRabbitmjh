#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
#include <math.h>
using namespace std;
//우선순위큐
priority_queue <int,vector<int>,greater<int>> q;
int n, m;
vector<vector<int>> v(32005);
int arr[32005];

void bfs() {
    //선행문제가 없는것만 queue에 푸시
	for (int i = 1; i <= n; i++)if (!arr[i])q.push(i);
	while (!q.empty()) {
		int next = q.top();
		q.pop();
		printf("%d ", next);
		for (int i = 0; i < v[next].size(); i++) {
            //next가 먼저 풀려야 풀 수 있는 문제
			int N = v[next][i];
			arr[N]--;
			if (!arr[N]) q.push(N);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		arr[b]++;
	}
	bfs();
	return 0;
}
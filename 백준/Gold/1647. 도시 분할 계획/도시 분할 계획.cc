#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
int n, m, sum, cnt;
priority_queue <pp> pq;
int parent[100005];

int find(int a) {
	if (a == parent[a])return a;
	else return parent[a] = find(parent[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[a] = b;
		return true;
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pq.push({ -c,{a,b} });
	}

	for (int i = 1; i <= n; i++)parent[i] = i;

	while (!pq.empty() && cnt < n - 2) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		if (!merge(a, b))continue;
		
		cnt++;
		sum += cost;
	}
	printf("%d", sum );

	return 0;
}
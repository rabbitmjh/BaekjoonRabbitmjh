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
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, p> pp;
int n, m, cnt;
priority_queue <pp> pq;
int parent[1005];
p arr[1005];

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
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
		
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int a = arr[i].first, b = arr[i].second;
			int x = arr[j].first, y = arr[j].second;
			ll cost = pow(a - x, 2) + pow(b - y, 2);
			pq.push({ -cost,{i,j} });
		}
	}

	double sum = 0;
	while (!pq.empty() && cnt < n - 1) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		if (!merge(a, b)) {
			pq.pop();
			continue;
		}
		cnt++;
		ll cost = -pq.top().first;
		sum += sqrt(cost);
		pq.pop();
	}
	printf("%.2lf", sum );

	return 0;
}
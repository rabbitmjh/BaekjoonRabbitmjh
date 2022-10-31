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
typedef pair<float, float> p;
typedef pair<float, p> pp;
int n, m, cnt;
priority_queue <pp> pq;
int parent[105];
p arr[105];

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
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%f %f", &arr[i].first, &arr[i].second);

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			float a = arr[i].first;
			float b = arr[i].second;
			float x = arr[j].first;
			float y = arr[j].second;

			pq.push({ -sqrt(pow(x - a,2) + pow(y - b,2)),{i,j} });
		}
	}
	for (int i = 1; i <= n; i++)parent[i] = i;

	float sum = 0;
	while (!pq.empty() && cnt < n - 1) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		float cost = -pq.top().first;
		pq.pop();
		if (!merge(a, b))continue;

		cnt++;
		sum += cost;
	}
	printf("%.2f", sum );

	return 0;
}
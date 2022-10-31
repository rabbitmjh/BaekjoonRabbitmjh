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
int n, m, sum;
vector <pp> v;
int com[1005];

int find(int a) {
	if (a == com[a])return a;
	return com[a] = find(com[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return false;
	com[a] = b;
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({ c,{a,b} });
	}
	for (int i = 1; i <= n; i++)com[i] = i;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (merge(v[i].second.first, v[i].second.second)) {
			sum += v[i].first;
		}
	}
	printf("%d", sum);

	return 0;
}
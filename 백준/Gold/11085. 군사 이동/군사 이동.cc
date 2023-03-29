#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, c, v, child[1005], parent[1005];
vector <pp> road;

int find(int num) {
	if (parent[num] < 0)return num;
	return parent[num] = find(parent[num]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[a] += parent[b];
	parent[b] = a;
}

int main() {
	FIO;
	cin >> n >> m >> c >> v;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road.push_back({ c,{a,b} });
	}
	sort(road.begin(), road.end(), greater<>());
	for (int i = 0; i < n; i++)
		parent[i] = -1;

	for (int i = 0; i < road.size(); i++) {
		uni(road[i].second.first, road[i].second.second);
		if (find(c) == find(v)) {
			cout << road[i].first;
			return 0;
		}
	}

	return 0;
}
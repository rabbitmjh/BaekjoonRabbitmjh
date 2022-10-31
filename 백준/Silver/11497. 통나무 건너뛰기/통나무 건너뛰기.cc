#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

queue<pair<int, int>>q;

int t, n, m;

int main() {
	scanf("%d", &t);
	while (t--) {
		vector<int>v;
		vector<int>v1;
		vector<int>v2;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			v.push_back(m);
		}
		sort(v.begin(), v.end(), greater<int>());
		v1.push_back(v[0]);
		v2.push_back(v[0]);
		for (int i = 1; i < v.size(); i++) {
			if (i % 2) v1.push_back(v[i]);
			else v2.push_back(v[i]);
		}
		int ans = 0;
		for (int i = 0; i < v1.size(); i++) {
			if (i == v1.size() - 1)continue;
			ans = max(ans, abs(v1[i] - v1[i + 1]));
		}
		for (int i = 0; i < v2.size(); i++) {
			if (i == v2.size() - 1)continue;
			ans = max(ans, abs(v2[i] - v2[i + 1]));
		}
		ans = max(ans, abs(v1.back() - v2.back()));
		printf("%d\n", ans);
	}
	return 0;
}
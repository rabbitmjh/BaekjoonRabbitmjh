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
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;


int main() {
	vector <vector<int>> v(100005);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
		v[a].push_back(b);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int cm = v[i].size();
		mx = max(mx, cm);
	}
	printf("%d\n", mx + 1);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans, b;
vector <int> ne, po;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a > 0)po.push_back(a);
		else ne.push_back(abs(a));
	}
	sort(ne.begin(), ne.end(), greater<>());
	sort(po.begin(), po.end(), greater<>());

	for (int i = 0; i < ne.size(); i += m)
		ans += ne[i] * 2;

	for (int i = 0; i < po.size(); i += m)
		ans += po[i] * 2;

	if (ne.empty())b = po.front();
	else if (po.empty())b = ne.front();
	else b = max(po.front(), ne.front());
	cout << ans - b;

	return 0;
}
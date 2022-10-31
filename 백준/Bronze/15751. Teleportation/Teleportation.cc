#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<string, p> pp;



int main() {
	int a, b, x, y;
	cin >> a >> b >> x >> y;

	int ans = abs(a - b);
	ans = min(min(abs(a - x) + abs(b - y), abs(a - y) + abs(b - x)), ans);
	cout << ans;

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <cmath>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, k, a, b, c, d;

int main() {
	FIO;
	cin >> n >> m >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		if ((x + y) % 2 == 1 && x % 2 == 1)a = 1;
		if ((x + y) % 2 == 1 && x % 2 == 0)b = 1;
		if ((x + y) % 2 == 0 && x % 2 == 1)c = 1;
		if ((x + y) % 2 == 0 && x % 2 == 0)d = 1;
	}
	if (a&&b&&c&&d)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
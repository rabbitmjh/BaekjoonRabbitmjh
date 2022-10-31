#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

int main() {
	std::ios::sync_with_stdio(false);
	int e, s, m;
	cin >> e >> s >> m;
	int i = 1;
	while (1) {
		if ((i - e) % 15 == 0 && (i - s) % 28 == 0 && (i - m) % 19 == 0) {
			cout << i;
			break;
		}
		i++;
	}
	

	return 0;
}
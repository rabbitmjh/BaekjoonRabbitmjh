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

string n;
int m, sum, num, cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	num = stoi(n);

	for (cnt; cnt < num; cnt++) {
		if (m - sum < n.size()) {
			break;
		}
		cout << n;
		sum += n.size();
	}
	if (cnt == num)
		return 0;
	
	if (sum < m) {
		for (int i = 0; sum < m; i++) {
			cout << n[i];
			sum++;
		}
	}
	return 0;
}
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

int n, m, q, i, j;
vector <int> a, b;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (n--) {
		cin >> q;
		a.push_back(q);
	}

	while (m--) {
		cin >> q;
		b.push_back(q);
	}

	while (i < a.size() && j < b.size()) {
 		if (a[i] > b[j]) {
			cout << b[j] << " ";
			j++;
		}
		else {
			cout << a[i] << " ";
			i++;
		}
	}

	if (i < a.size())
		for (i; i < a.size(); i++)
			cout << a[i] << " ";

	if (j < b.size())
		for (j; j < b.size(); j++)
			cout << b[j] << " ";

	return 0;
}
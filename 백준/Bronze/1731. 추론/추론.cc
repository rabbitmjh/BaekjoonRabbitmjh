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

int n, a;
vector <int> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--) {
		int a; cin >> a;
		v.push_back(a);
	}

	if (v[2] - v[1] == v[1] - v[0])
		cout << v.back() + v[1] - v[0];
	else
		cout << v.back() * (v[1] / v[0]);
	
	return 0;
}
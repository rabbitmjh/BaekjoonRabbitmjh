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

int n, m;
vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (!i)v.push_back(m);
		else {
			if (v.back() < m)
				v.push_back(m);
			else {
				auto it = lower_bound(v.begin(), v.end(), m);
				*it = m;
			}
		}
	}
	
	cout << v.size();

	return 0;
}
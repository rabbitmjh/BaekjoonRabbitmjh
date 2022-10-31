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

int n, sum;
string s;
vector <int> m, b, z;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a < 0)
			m.push_back(a);
		else if (a > 0)
			b.push_back(a);
		else
			z.push_back(a);
	}
	sort(m.begin(), m.end());
	sort(b.begin(), b.end(),greater<>());
	
	while (b.size() > 1) {
		if (b.size() == 1)break;
		else {
			if (b[0] == 1 || b[1] == 1) {
				sum += b[0] + b[0 + 1];
				b.erase(b.begin());
				b.erase(b.begin());
			}
			else {
				sum += b[0] * b[1];
				b.erase(b.begin());
				b.erase(b.begin());
			}
		}
		if (b.size() == 1)break;
	}

	while (m.size() > 1) {
		if (m.size() == 1)break;
		else {
			sum += m[0] * m[1];
			m.erase(m.begin());
			m.erase(m.begin());
		}
		if (m.size() == 1)break;
	}

	if (m.size() > 0 && z.empty()) {
		sum += m[0];
		m.pop_back();
	}

	if (b.size() > 0)
		sum += b[0];

	cout << sum;
	return 0;
}
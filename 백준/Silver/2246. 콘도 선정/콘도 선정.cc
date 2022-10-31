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

int n, d, c, cnt;
vector <p> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	while (n--) {
		cin >> d >> c;
		v.push_back({ d,c });
	}

	for (int i = 0; i < v.size(); i++) {
		bool near = true, far = true;

		for (int j = 0; j < v.size(); j++) {
			if (i == j) continue;
			if (v[i].first > v[j].first && v[i].second >= v[j].second)//가까우면서 싸거나 같은지
				near = false;
			if (v[i].second > v[j].second && v[i].first >= v[j].first)//싸면서 가깝거나 같은지
				far = false;
		}
		if (near && far)
			cnt++;
	}

	cout << cnt;

	return 0;
}
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

int n;
vector<int> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int m;
			cin >> m;
			v.push_back(m);
		}
		else if (s == "top") {
			if (v.empty())
				cout << -1 << endl;
			else
				cout << v.back() << endl;
		}
		else if (s == "size") {
			cout << v.size() << endl;
		}
		else if (s == "empty") {
			cout << v.empty() << endl;
		}
		else {
			//pop
			if (v.empty())
				cout << -1 << endl;
			else {
				cout << v.back() << endl;
				v.pop_back();
			}

		}
	}
	return 0;
}
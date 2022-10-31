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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	while (n--) {
		int num;
		string s;
		cin >> num >> s;
		s.erase(num - 1, 1);
		cout << s << "\n";
	}

	return 0;
}
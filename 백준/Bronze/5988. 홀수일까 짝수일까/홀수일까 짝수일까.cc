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

int n, arr[500005];
string s;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--) {
		cin >> s;
		int num = s[s.size() - 1] - '0';
		
		if (!(num % 2))
			cout << "even" << "\n";
		else
			cout << "odd" << "\n";
	}
	return 0;
}
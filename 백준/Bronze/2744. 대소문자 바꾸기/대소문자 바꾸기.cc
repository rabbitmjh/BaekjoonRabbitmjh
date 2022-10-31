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

string s, ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < 'a')
			ans += tolower(s[i]);
		else
			ans += toupper(s[i]);
	}
	cout << ans;

	return 0;
}
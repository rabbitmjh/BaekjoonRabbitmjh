#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

string s;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> s;
	int ans = 10;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == s[i])ans += 5;
		else ans += 10;
	}
	cout << ans;
	return 0;
}
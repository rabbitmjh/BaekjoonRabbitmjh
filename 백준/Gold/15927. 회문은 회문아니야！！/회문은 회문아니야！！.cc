#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<string, p> pp;

int main() {
	bool check = true;
	string s;
	cin >> s;
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size() - 1 - i])check = false;

	if (!check)cout << s.size();
	else {
		for (int i = 0; i < s.size() / 2; i++)
			if (s[i] != s[s.size() - 2 - i])check = false;

		if (check)cout << -1;
		else cout << s.size() - 1;
	}

	return 0;
}
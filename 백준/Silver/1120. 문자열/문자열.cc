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
string s1, s2;
int n, ans = 100, cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s1 >> s2;
	n = s2.size() - s1.size();


	for (int i = 0; i <= n; i++) {
		for (int k = 0; k < s1.size(); k++) {
			if (s2[k + i] != s1[k])
				cnt++;
		}
		ans = min(ans, cnt);
		cnt = 0;
	}

	cout << ans;
	return 0;
}
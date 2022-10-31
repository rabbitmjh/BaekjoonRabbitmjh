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

p arr[100005];
int n, m, t;
string s;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] == s[s.size() - i - 1])cnt++;
	}
	if (cnt == s.size() / 2)cout << 1;
	else cout << 0;
	return 0;
}
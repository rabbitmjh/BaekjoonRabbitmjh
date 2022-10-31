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

string s[1000005];
int cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
		if (s[i] == ' ')
			cnt++;
			
	if (s[0] == ' ')cnt--;
	if (s[s.size() - 1] == ' ')cnt--;
	cout << cnt + 1;

	return 0;
}
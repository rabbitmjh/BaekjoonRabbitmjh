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
string s;
vector <ll> v, str;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	while (n--) {
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(stoll(s));
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}
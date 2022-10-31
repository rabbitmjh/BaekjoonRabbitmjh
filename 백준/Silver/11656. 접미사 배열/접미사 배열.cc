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
vector <vector<char>> v(1005);

int main() {
	std::ios::sync_with_stdio(false);
	cin >> s;

	
	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			v[i].push_back(s[j]);
		}
	}
	sort(v.begin(), v.begin() + s.size());

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j];
		cout << "\n";
	}
	return 0;
}
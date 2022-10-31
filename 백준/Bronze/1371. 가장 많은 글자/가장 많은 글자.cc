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

vector <string> v;
string s;
p arr[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> s) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ')
				arr[s[i] - 'a'].first++;
		}
		s.clear();
	}

	for (int i = 0; i < 26; i++)
		arr[i].second = i + 'a';
	sort(arr, arr + 26);
	
	int i = 0;
	while (i < 26) {
		if (arr[i].first == arr[25].first)
			cout << char(arr[i].second);
		i++;
	}

	return 0;
}
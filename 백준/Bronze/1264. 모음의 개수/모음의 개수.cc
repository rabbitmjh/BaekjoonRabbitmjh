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

string s;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		getline(cin, s);
		if (s == "#") break;
		
		int cnt = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
				cnt++;
		
		cout << cnt << "\n";
	}
	return 0;
}
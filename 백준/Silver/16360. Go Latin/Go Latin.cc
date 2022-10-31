#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.back() == 'a')s.append("s");
		else if (s.back() == 'y' || s.back() == 'i') {
			s.pop_back();
			s.append("ios");
		}
		else if (s.back() == 'l') s.append("es");
		else if (s.back() == 'n') {
			s.pop_back();
			s.append("anes");
		}
		else if (s[s.size() - 2] == 'n'&&s.back() == 'e') {
			s.pop_back();
			s.pop_back();
			s.append("anes");
		}
		else if (s.back() == 'o')s.append("s");
		else if (s.back() == 'r')s.append("es");
		else if (s.back() == 't')s.append("as");
		else if (s.back() == 'u')s.append("s");
		else if (s.back() == 'v')s.append("es");
		else if (s.back() == 'w')s.append("as");
		else s.append("us");
		cout << s << endl;
	}
	return 0;
}
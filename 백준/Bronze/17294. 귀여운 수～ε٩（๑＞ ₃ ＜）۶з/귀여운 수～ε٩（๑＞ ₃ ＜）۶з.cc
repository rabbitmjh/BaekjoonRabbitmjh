#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

string n = "0", s;
int main() {
	cin >> s;
	if (s.size() < 2) {
		printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
		return 0;
	}
	else {
		int cnt = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			if(i==0) cnt = s[i] - s[i + 1];
			else {
				if (cnt != s[i] - s[i + 1]) {
					printf("흥칫뿡!! <(￣ ﹌ ￣)>");
					return 0;
				}
			}
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
string s;
int n;
int main() {
	cin >> s >> n;
	int a = s.size();
	bool check = true;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[a - 1 - i]) {
			check = false;
			break;
		}
	}
	if (check)printf("YES");
	else printf("NO");
	return 0;
}
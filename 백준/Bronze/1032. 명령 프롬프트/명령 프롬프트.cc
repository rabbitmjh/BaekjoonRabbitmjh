#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string a;
vector <string> s;
char st[55];
int n,c;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.push_back(a);
		c = a.size();
	}
	for (int i = 0; i < c; i++) {
		st[i] = s[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < c; j++) {
			if (s[i][j] != s[i - 1][j]) {
				st[j] = 0;
			}
		}
	}
	for (int i = 0; i < c; i++) {
		if (st[i] != 0) {
			printf("%c", st[i]);
		}
		else {
			printf("?");
		}
	}
	return 0;
}
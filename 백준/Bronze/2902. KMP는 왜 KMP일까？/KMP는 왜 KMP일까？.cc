#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

string s;
vector <char> v;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0)v.push_back(s[0]);
		if (i > 0 && s[i - 1] == '-') {
			v.push_back(s[i]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%c", v[i]);
	}
	return 0;
}
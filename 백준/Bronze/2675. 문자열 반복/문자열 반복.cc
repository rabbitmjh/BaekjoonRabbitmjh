#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string s;
int n,a;
int main() {
	cin >> n;
	while (n--) {
		cin >> a >> s;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < a; j++) {
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
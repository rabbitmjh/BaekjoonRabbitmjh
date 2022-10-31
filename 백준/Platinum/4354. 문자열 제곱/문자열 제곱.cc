#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n;
string s;


int main() {
	while (1) {
		char s[1000005];
		scanf("%s", s);
		if (s[0] == '.') return 0;
		int j = 0;
		n = strlen(s);
		int pi[1000005] = { 0 };
		for (int i = 1; i < n; i++) {
			while (j > 0 && s[i] != s[j])j = pi[j - 1];
			if (s[i] == s[j])pi[i] = ++j;
		}
		
		int chk1 = pi[n - 1];
		int chk2 = n - chk1;
		if (!chk1 || chk1 % chk2 != 0) puts("1");
		else printf("%d\n", chk1 / chk2 + 1);
	}

	return 0;
}

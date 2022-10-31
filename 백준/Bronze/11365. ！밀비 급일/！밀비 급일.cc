#include <iostream>
#include <algorithm>
#include <string.h>
#include <functional>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s == "END")break;
		for (int i = s.size() - 1; i >= 0; i--)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
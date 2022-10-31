#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main() {
	string s, cmp1, cmp2;
	cin >> cmp1 >> s >> cmp2;
	if (s == "AND") {
		if ((cmp1 == "true" || cmp2 == "true") && cmp1 == cmp2)cout << "true";
		else cout << "false" << endl;
	}
	else {
		if(cmp1 == "true" || cmp2 == "true")cout << "true";
		else cout << "false" << endl;
	}
	return 0;
}
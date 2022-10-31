#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string a;
int s[3];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s[0] = a[0], s[2] = a[2];

		printf("%d\n",(s[0]+s[2])-96);
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string a;
int s[26];
int n;

int main() {
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'a')s[0]++;
		else if (a[i] == 'b')s[1]++;
		else if (a[i] == 'c')s[2]++;
		else if (a[i] == 'd')s[3]++;
		else if (a[i] == 'e')s[4]++;
		else if (a[i] == 'f')s[5]++;
		else if (a[i] == 'g')s[6]++;
		else if (a[i] == 'h')s[7]++;
		else if (a[i] == 'i')s[8]++;
		else if (a[i] == 'j')s[9]++;
		else if (a[i] == 'k')s[10]++;
		else if (a[i] == 'l')s[11]++;
		else if (a[i] == 'm')s[12]++;
		else if (a[i] == 'n')s[13]++;
		else if (a[i] == 'o')s[14]++;
		else if (a[i] == 'p')s[15]++;
		else if (a[i] == 'q')s[16]++;
		else if (a[i] == 'r')s[17]++;
		else if (a[i] == 's')s[18]++;
		else if (a[i] == 't')s[19]++;
		else if (a[i] == 'u')s[20]++;
		else if (a[i] == 'v')s[21]++;
		else if (a[i] == 'w')s[22]++;
		else if (a[i] == 'x')s[23]++;
		else if (a[i] == 'y')s[24]++;
		else if (a[i] == 'z')s[25]++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", s[i]);
	}
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<string.h>
using namespace std;
int n[8];

int main() {
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '1' || s[i] =='Q' || s[i] == 'A' || s[i] == 'Z')n[0]++;
		else if (s[i] == '2' || s[i] == 'W' || s[i] == 'S' || s[i] == 'X')n[1]++;
		else if (s[i] == '3' || s[i] == 'E' || s[i] == 'D' || s[i] == 'C')n[2]++;
		else if (s[i] == '4' || s[i] == 'R' || s[i] == 'F' || s[i] == 'V' || s[i] == '5' || s[i] == 'T' || s[i] == 'G' || s[i] == 'B')n[3]++;
		else if (s[i] == '6' || s[i] == 'Y' || s[i] == 'H' || s[i] == 'N' || s[i] == '7' || s[i] == 'U' || s[i] == 'J' || s[i] == 'M')n[4]++;
		else if (s[i] == '8' || s[i] == 'I' || s[i] == 'K' || s[i] == ',')n[5]++;
		else if (s[i] == '9' || s[i] == 'O' || s[i] == 'L' || s[i] == '.')n[6]++;
		else n[7]++;
	}
	for (int i = 0; i < 8; i++) {
		printf("%d\n", n[i]);
	}
	return 0;
}
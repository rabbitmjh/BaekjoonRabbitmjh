#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string a;
char s[105];
int n;

int main() {
	getline(cin, a);
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'a')s[i]='n';
		else if (a[i] == 'b')s[i]='o';
		else if (a[i] == 'c')s[i]='p';
		else if (a[i] == 'd')s[i]='q';
		else if (a[i] == 'e')s[i]='r';
		else if (a[i] == 'f')s[i]='s';
		else if (a[i] == 'g')s[i]='t';
		else if (a[i] == 'h')s[i]='u';
		else if (a[i] == 'i')s[i]='v';
		else if (a[i] == 'j')s[i]='w';
		else if (a[i] == 'k')s[i]='x';
		else if (a[i] == 'l')s[i]='y';
		else if (a[i] == 'm')s[i]='z';
		else if (a[i] == 'n')s[i]='a';
		else if (a[i] == 'o')s[i]='b';
		else if (a[i] == 'p')s[i]='c';
		else if (a[i] == 'q')s[i]='d';
		else if (a[i] == 'r')s[i]='e';
		else if (a[i] == 's')s[i]='f';
		else if (a[i] == 't')s[i]='g';
		else if (a[i] == 'u')s[i]='h';
		else if (a[i] == 'v')s[i]='i';
		else if (a[i] == 'w')s[i]='j';
		else if (a[i] == 'x')s[i]='k';
		else if (a[i] == 'y')s[i]='l';
		else if (a[i] == 'z')s[i]='m';
		else if (a[i] == ' ')s[i] =' ';
		else if (a[i] == 'A')s[i] = 'N';
		else if (a[i] == 'B')s[i] = 'O';
		else if (a[i] == 'C')s[i] = 'P';
		else if (a[i] == 'D')s[i] = 'Q';
		else if (a[i] == 'E')s[i] = 'R';
		else if (a[i] == 'F')s[i] = 'S';
		else if (a[i] == 'G')s[i] = 'T';
		else if (a[i] == 'H')s[i] = 'U';
		else if (a[i] == 'I')s[i] = 'V';
		else if (a[i] == 'J')s[i] = 'W';
		else if (a[i] == 'K')s[i] = 'X';
		else if (a[i] == 'L')s[i] = 'Y';
		else if (a[i] == 'M')s[i] = 'Z';
		else if (a[i] == 'N')s[i] = 'A';
		else if (a[i] == 'O')s[i] = 'B';
		else if (a[i] == 'P')s[i] = 'C';
		else if (a[i] == 'Q')s[i] = 'D';
		else if (a[i] == 'R')s[i] = 'E';
		else if (a[i] == 'S')s[i] = 'F';
		else if (a[i] == 'T')s[i] = 'G';
		else if (a[i] == 'U')s[i] = 'H';
		else if (a[i] == 'V')s[i] = 'I';
		else if (a[i] == 'W')s[i] = 'J';
		else if (a[i] == 'X')s[i] = 'K';
		else if (a[i] == 'Y')s[i] = 'L';
		else if (a[i] == 'Z')s[i] = 'M';
		else s[i] = a[i];
	}
	for (int i = 0; i < a.size(); i++) {
		printf("%c",s[i]);
	}
	return 0;
}
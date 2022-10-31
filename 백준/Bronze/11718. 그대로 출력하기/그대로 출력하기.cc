#include <iostream>
#include <string>

using namespace std;
char ch;
int main() {

	ch = getchar();

	while (ch != -1) {
		putchar(ch);
		ch = getchar();
	}

	return 0;
}

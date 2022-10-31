#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;

char ch[105];
int n,a;

int main() {
	scanf("%d", &n);
	cin.getline(ch, 105);
	while (n--) {
		cin.getline(ch, 105);
		for (int i = 0; i < sizeof(ch); i++) {
			if (ch[i] == ' ') {
				a = i;
				break;
			}
		}
		printf("god");
		for (int i = a; i < sizeof(ch); i++) {
			if (ch[i] == ' ')continue;
			else if (ch[i] == '\0')break;
			else printf("%c", ch[i]);
		}
		printf("\n");
	}



}
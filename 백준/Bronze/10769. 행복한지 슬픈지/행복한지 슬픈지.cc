#include<string>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<iostream>

using namespace std;
string t;
int g, s;
int main() {
	getline(cin, t);
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == ':') {
			if (t[i + 1] == '-') {
				if (t[i + 2] == ')') {
					g++;
					continue;
				}
				else if (t[i + 2] == '(') {
					s++;
					continue;
				}
				continue;
			}
			continue;
		}
	}
	if (g == 0 && s == 0) {
		printf("none");
	}
	else if (g == s) {
		printf("unsure");
	}
	else if (g > s) {
		printf("happy");
	}
	else if (g < s) {
		printf("sad");
	}
	return 0;
}
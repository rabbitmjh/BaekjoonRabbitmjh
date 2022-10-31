#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<string.h>
using namespace std;
int n,m,a;

int main() {
	cin >> n >> m;
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < m; i++) {
		a = 0;
		string d;
		cin >> d;
		for (int j = 0; j < d.length(); j++) {
			if (s[a] == d[j]) {
				a++;
				if (a == len) {
					printf("true\n");
					break;
				}
			}
		}
		if (a != len) {
			printf("false\n");
		}
	}
	
	return 0;
}
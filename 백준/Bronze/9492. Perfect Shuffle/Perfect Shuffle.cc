#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cstdio>
using namespace std;

int n;

int main() {
	while (1) {
		string str[1005];
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		if (n % 2 == 0) {
			for (int i = 0; i < n / 2; i++) {
				cout << str[i] << endl;
				cout << str[i + n/2] << endl;
			}
		}
		else {
			for (int i = 0; i < (n / 2); i++) {
				
				cout << str[i] << endl;
				cout << str[i + (n / 2)+1] << endl;
			}
			cout << str[n/2 ] << endl;
		}
		
	}
	return 0;

}

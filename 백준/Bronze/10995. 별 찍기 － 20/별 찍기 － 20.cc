#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int n,a;
vector <int> v;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n * 2 - 1; j++) {
				if (j % 2 == 0)printf(" ");
				else printf("*");
			}
		}
		else {
			for (int j = 1; j <= n * 2; j++) {
				if (j % 2 == 1)printf(" ");
				else printf("*");
			}
		}
		printf("\n");
	}
	
	return 0;
}
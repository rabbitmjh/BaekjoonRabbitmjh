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
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		printf("*");
		for (int j = 1; j <= (i - 1) * 2 - 1; j++) {
			if (j == 1)printf(" ");
			else if (j % 2 == 0)printf("*");
			else printf(" ");
		}
		if(i!=1)printf("*");
		printf("\n");
	}
	
	return 0;
}
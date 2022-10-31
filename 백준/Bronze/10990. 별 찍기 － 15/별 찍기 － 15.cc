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
		for (int j = 0; j < (i - 1) * 2 - 1; j++) {
			printf(" ");
		}
		if(i!=1)printf("*");
		printf("\n");
	}
	
	return 0;
}
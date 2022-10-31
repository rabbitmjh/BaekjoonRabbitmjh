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
		for (int j = 1; j <= n; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
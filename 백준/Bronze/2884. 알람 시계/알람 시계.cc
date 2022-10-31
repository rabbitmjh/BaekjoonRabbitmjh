#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, n1;

int main() {
	scanf("%d %d", &n, &n1);
	if (n == 0 && n1<45) {
		printf("%d %d", 23, n1 + 15);
	}
	else if (n1 < 45) {
		printf("%d %d", n - 1, n1 + 15);
	}
	else {
		printf("%d %d", n, n1 - 45);
	}


	return 0;
}
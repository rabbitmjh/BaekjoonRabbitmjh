#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c - b == 1 && b - a == 1) {
		printf("0\n0");
		return 0;
	}
	else if (c - b == 2 || b - a == 2) {
		printf("1\n");
	}
	else {
		printf("2\n");
	}
	int mx = max((b - a), (c - b));
	printf("%d\n", mx - 1);
	return 0;
}
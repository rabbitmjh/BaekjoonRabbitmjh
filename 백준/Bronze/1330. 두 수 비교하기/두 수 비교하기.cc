#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
int n, m, t;

int main() {
	cin >> n >> m;
	if (n < m)printf("<");
	else if (n>m)printf(">");
	else printf("==");
	return 0;
}

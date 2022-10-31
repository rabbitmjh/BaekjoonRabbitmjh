#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int n;

int main() {
	cin >> n;
	if (n % 4 == 0 && n % 100 == 0 && n % 400 != 0)printf("0");
	else if (n % 4 == 0 || n % 400 == 0)printf("1");
	else printf("0");

	return 0;
}
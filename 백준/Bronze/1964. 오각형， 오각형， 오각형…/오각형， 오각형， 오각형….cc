#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int n,a,b;

int main() {
	scanf("%d", &n);
	a = 5;
	b = 7;
	for (int i = 2; i <= n; i++) {
		a = (a + b) % 45678;
		b += 3;
	}
	printf("%d", a);

	return 0;
}
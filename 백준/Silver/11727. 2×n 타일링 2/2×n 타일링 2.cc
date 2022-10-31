#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
long long a[1005];
int n;
int tile(int n,int i) {
	a[i] = (a[i - 1] + 2 * a[i - 2]) % 10007;
	if (n == i)return a[i];
	else return tile(n, i + 1);
}
int main() {
	cin >> n;
	a[1]=1,a[2] = 3;
	if (n > 2) {
		tile(n, 3);
		printf("%lld", a[n]);
	}
	else printf("%lld", a[n]);
	return 0;
}
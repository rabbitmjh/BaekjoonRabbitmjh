#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

ll t, n, a, b;

int main() {
	cin >> t;
	while (t--) {
		int cnt = 0;
		ll c = 0, num = 1;
		scanf("%lld%lld%lld", &n, &a, &b);
		c = max(a, b);
		b = min(a, b);
		a = c;
		num = pow(2, n);

		c = 0;
		while (1) {
			if (b >= num) {
				if (c == b) {
					printf("%d\n", cnt - 1);
					break;
				}
				else {
					if(c+num<=b)
						c += num;
				}
			}
			num /= 2;
			cnt++;
		}
	}
	return 0;
}
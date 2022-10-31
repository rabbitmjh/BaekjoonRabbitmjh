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
typedef pair < p,int> pp;
typedef long long ll;
vector <string> v;
int n, t;
ll arr[70][10] = {1,1,1,1,1,1,1,1,1,1,};
ll ans[65] = { 0,9 };


int main() {
	cin >> t;
	for (int i = 1; i <= 64; i++) {
		for (int j = 0; j < 10; j++) {
			ll m = 0;
			for (int k = j; k < 10; k++) {
				m += arr[i - 1][k];
			}
			arr[i][j] = m;
		}
		ans[i] = arr[i][0];
	}
	while (t--) {
		cin >> n;
		printf("%lld\n", ans[n]);
	}
	return 0;
}
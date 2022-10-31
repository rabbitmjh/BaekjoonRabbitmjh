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


int main() {
	int n, cnt = 0, mx = 1e9;
	vector <int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] < mx) {
			cnt++;
			mx = v[i];
		}
		else break;
	}
	printf("%d\n", n - cnt);
	return 0;
}
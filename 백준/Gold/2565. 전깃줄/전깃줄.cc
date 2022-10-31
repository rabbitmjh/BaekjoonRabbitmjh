#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <limits.h>
using namespace std;
typedef pair <int, int> p;
typedef long long ll;

int n, ans;
vector <p> v;
vector <int> v1;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	v1.push_back(-1e9);
	for (int i = 0; i < n; i++) {
		int k = v[i].second;
		if (v1.back() < k) {
			v1.push_back(k);
			ans++;
		}
		else {
			auto it = lower_bound(v1.begin(), v1.end(), k);
			*it = k;
		}
	}
	
	printf("%d", n- ans);
	return 0;
}
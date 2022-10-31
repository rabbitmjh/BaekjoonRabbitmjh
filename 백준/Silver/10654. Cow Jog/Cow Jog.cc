#include <iostream>
#include <algorithm>
#include <functional> 
#include <vector>
#include <utility>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> p;

int n, t;
vector <p> v;

int main() {
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}

	int sum = 0;
	ll m = 1e20 + 5;

	for (int i = v.size() - 1; i >= 0; i--) {
		v[i].second = v[i].second * t + v[i].first;
		if (v[i].second < m) {
			sum++;
			m = min(m, v[i].second);
		}
	}

	printf("%d", sum);

	return 0;
}

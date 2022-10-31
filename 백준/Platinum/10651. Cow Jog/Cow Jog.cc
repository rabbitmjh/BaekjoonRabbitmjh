#include <iostream>
#include <algorithm>
#include <functional> 
#include <vector>
#include <utility>
#include <math.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> p;
typedef pair<ll, p> pp;

ll n, t, sum;
vector <ll> v;

int main() {
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ll c = -(b*t + a);
		if (v.empty() || c >= v.back())v.push_back(c);
		else *upper_bound(v.begin(), v.end(), c) = c;
	}
	printf("%d", v.size());

	return 0;
}

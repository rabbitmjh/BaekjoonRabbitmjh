#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long  long ll;
typedef pair <ll , ll > p;
vector <p> v;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	ll ans = 0;
	
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1)
			ans += (v[i].first + v[0].first) * (v[0].second - v[i].second);
		else ans += (v[i].first + v[i + 1].first)* (v[i + 1].second - v[i].second);
	}
	if (ans % 2 == 0)printf("%lld.0", abs(ans) / 2);
	else printf("%lld.5", abs(ans) / 2);

	//tlqkf wrkxdmsrj wsk dksehlsp wlaltlqkfrjt
	return 0;
}
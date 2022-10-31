#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll a, b;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> a >> b;
	if (a == b) {
		cout << 0;
		return 0;
	}

	cout << abs(b - a) - 1 << endl;
	ll c = max(a, b), d = min(a, b);
	
	for (ll i = d + 1; i < c; i++) 
		cout << i << " ";
	

	

	return 0;
}
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
//백준 6064 카잉 달력

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	
	while(t--) {
		int m, n, x, y, ans;
		cin >> m >> n >> x >> y;
		bool check = true;
		ans = x;
		y %= n;
		while(1) {
			if(ans > m * n) {
				check = false;
				break;
			}
			if((ans % n) == y)
				break;
			ans += m;
		}
		
		if(check) cout << ans << endl;
		else cout << -1 << endl;
		ans = 0;
	}
	
	return 0;
}
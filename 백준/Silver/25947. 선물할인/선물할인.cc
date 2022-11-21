#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <deque>
#include <string>
#include <climits>
#include <cmath>
#include <string>
#include <array>
#include <map>
#include <set>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
/*
Ok_Hwang
team290
svp74kdj
*/

ll n, b, a, sum, w, l, r, ans;
vector <ll> v;


int main() {
	FIO;
	cin >> n >> b >> a;
	for (int i = 0;i < n;i++) {
		int c;cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < a;i++) {
		sum += v[i] / 2;
		ans++;
		if (sum > b) {
			ans--;
			sum -= v[i] / 2;
			r = i;
			break;
		}
		else {
			r = i + 1;
		}
	}
	if (a == 0) {
		for (int i = 0;i < n;i++) {
			sum += v[i];
			ans++;
			if (sum > b) {
				ans--;
				sum -= v[i];
				break;
			}
		}
	}
	
	while (l < n && r < n && a) {
		sum += v[l] / 2;
		sum += v[r] / 2;
		l++;
		r++;
		if (sum > b) {
			break;
		}
		else {
			ans++;
		}
	}

	cout << ans;
	return 0;
}
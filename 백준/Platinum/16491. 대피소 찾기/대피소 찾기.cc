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
typedef pair<int, int> p;
typedef pair<p, int> pp;
typedef pair<p, p> ppp;
vector <pp> v;
vector <pp> r;
vector <int> ans;
int ccw(p x, p y, p z) {
	int x1 = x.first, y1 = x.second;
	int x2 = y.first, y2 = y.second;
	int x3 = z.first, y3 = z.second;
	int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0)return 1;
	else if (temp < 0)return -1;
	else return 0;
}

bool inter(p a, p b, p c, p d) {
   ll x1 = a.first, y1 = a.second, x2 = b.first, y2 = b.second, x3 = c.first, y3 = c.second,x4=d.first,y4=d.second;
   if (x1 == x2 && x2 == x3 && x3 == x4 && x4 == x1) {
      ll mx = max(y1, y2);
      ll mn = min(y3, y4);
      if (mx < mn) return false;
      mx = max(y3, y4);
      mn = min(y1, y2);
      if (mx < mn) return false;
   }
   else {
      ll mx = max(x1, x2);
      ll mn = min(x3, x4);
      if (mx < mn) return false;
      mx = max(x3, x4);
      mn = min(x1, x2);
      if (mx < mn) return false;
   }
   return true;
}


int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ { a,b },i });
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		r.push_back({ { a,b }, i });
	}
	sort(r.begin(), r.end());
	do {
		int chk = 0;
		vector <ppp> sum;
		for (int i = 0; i < v.size(); i++)sum.push_back({ v[i].first,r[i].first });
		for (int i = 0; i < sum.size(); i++) {
			for (int j = i + 1; j < sum.size(); j++) {
				ll a = ccw(sum[i].first, sum[i].second, sum[j].first);
				ll b = ccw(sum[i].first, sum[i].second, sum[j].second);
				ll c = ccw(sum[j].first, sum[j].second, sum[i].first);
				ll d = ccw(sum[j].first, sum[j].second, sum[i].second);
				if (a*b > 0 || c * d > 0)continue;
				else {
					if (inter(sum[i].first, sum[i].second, sum[j].first, sum[j].second)) {
						chk = 1;
						break;
					}
				}

			}
			if (chk)break;
		}
		if (!chk) {
			for (int i = 0; i < v.size(); i++)ans.push_back(r[i].second);
			break;
		}
	} while (next_permutation(r.begin(), r.end()));

	for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i] + 1);
	return 0;
}
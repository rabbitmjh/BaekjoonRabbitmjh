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

int t, ans, sum;
vector <int> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());

		int st = 0, en = v.size() - 1;
		int gap = abs(k - (v[st] + v[en]));
		ans = 0;

		while (st < en) {
			sum = v[st] + v[en];
			if (sum < k || sum > k) {//합이 k보다 작을 때
				if (abs(k - sum) < gap) {//k-합이 기존보다 작을 때
					gap = abs(k - sum);
					ans = 1;
				}
				else if (abs(k - sum) == gap)//k-합이 기존과 같을 때
					ans++;
			}
			else {//합이 k와 같을 때
				if (abs(k - sum) < gap) {
					gap = abs(k - sum);
					ans = 1;
				}
				else
					ans++;
			}
			int nextSt = abs(k - (v[st + 1] + v[en]));
			int nextEn = abs(k - (v[st] + v[en - 1]));
			if (nextSt <= nextEn) {
				//다음 차례에서 차이가 낮은것 부터
				st++;
			}
			else en--;
		}
		cout << ans << "\n";
		v.clear();
	}

	return 0;
}
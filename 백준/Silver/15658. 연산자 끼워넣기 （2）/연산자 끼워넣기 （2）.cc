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

vector <int> v;
int n, ad, su, mu, di;
int ma = -1000000001, mi = 1000000001;

int divByNegative(int sum, int di) {//양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로
	sum = abs(sum);
	sum /= di;
	sum *= -1;
	return sum;
}

void dfs(int ad, int su, int mu, int di, int sum, int cnt) {
	if (cnt == v.size()) {
		ma = max(ma, sum);
		mi = min(mi, sum);
		return;
	}

	if (ad > 0)dfs(ad - 1, su, mu, di, sum + v[cnt], cnt + 1);
	if (su > 0)dfs(ad, su - 1, mu, di, sum - v[cnt], cnt + 1);
	if (mu > 0)dfs(ad, su, mu - 1, di, sum * v[cnt], cnt + 1);
	if (di > 0) {
		int a = 0;
		if (sum < 0) {
			a = divByNegative(sum, v[cnt]);
			dfs(ad, su, mu, di - 1, a, cnt + 1);
		}
		else
			dfs(ad, su, mu, di - 1, sum / v[cnt], cnt + 1);
	}
	return;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	cin >> ad >> su >> mu >> di;
	dfs(ad, su, mu, di, v[0], 1);

	cout << ma << "\n" << mi;


	return 0;
}
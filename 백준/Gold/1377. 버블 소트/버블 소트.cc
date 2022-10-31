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

vector <p> v;
int n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back({ a,i });
	}
	sort(v.begin(), v.end());

	int ma = 0;
	for (int i = 0; i < n; i++)
		ma = max(v[i].second - i, ma);
	
	cout << ma + 1;
	return 0;
}
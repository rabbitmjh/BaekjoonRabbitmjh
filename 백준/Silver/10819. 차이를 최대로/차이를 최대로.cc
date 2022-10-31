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

int n, sum1, sum2;
vector <int> ans1, ans2, cmp1, cmp2;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		cmp1.push_back(a);
	}

	sort(cmp1.begin(), cmp1.end());
	cmp2 = cmp1;
	int mid = cmp1[cmp1.size() / 2];

	ans1.push_back(mid);
	ans2.push_back(mid);
	cmp1.erase(cmp1.begin() + cmp1.size() / 2);
	cmp2.erase(cmp2.begin() + cmp2.size() / 2);

	while (!cmp1.empty()) {
		ans1.push_back(cmp1.front());
		cmp1.erase(cmp1.begin());
		if (cmp1.empty())break;

		ans1.push_back(cmp1.back());
		cmp1.erase(cmp1.begin() + cmp1.size() - 1);
		if (cmp1.empty())break;
	}

	while (!cmp2.empty()) {
		ans2.push_back(cmp2.back());
		cmp2.erase(cmp2.begin() + cmp2.size() - 1);
		if (cmp2.empty())break;

		ans2.push_back(cmp2.front());
		cmp2.erase(cmp2.begin());
		if (cmp2.empty())break;
	}
	
	
	for (int i = 1; i < ans1.size(); i++)
		sum1 += abs(ans1[i - 1] - ans1[i]);

	for (int i = 1; i < ans2.size(); i++)
		sum2 += abs(ans2[i - 1] - ans2[i]);

	cout << max(sum1,sum2);
	return 0;
}
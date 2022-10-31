#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;

vector <p> v;
vector <vector<int>> ans(10);


int main() {
	int n, a;
	cin >> n;
	int x = pow(2, n) - 1;
	for (int i = 0; i < x; i++) {
		cin >> a;
		v.push_back({ a,0 });
	}

	for (int i = n-1; i > -1; i--) {
		for (int k = 0; k < v.size(); k++) {
			if (!v[k].second) {
				for (int j = k; j < v.size(); j += 2) {
					ans[i].push_back(v[j].first);
					v[j].second = i;
				}
				break;
			}
		}
		for (int k = 0; k < v.size(); k++) {
			if (v[k].second == i)
				v.erase(v.begin() + k, v.begin() + k + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}

	return 0;
}
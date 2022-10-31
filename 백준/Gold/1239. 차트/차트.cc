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

int arr[105];
vector <int> v;

int main() {
	int n; cin >> n;
	bool chk = true, f = true;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
		if (a > 50)chk = false;
		if (a == 50)f = false;
	}
	sort(v.begin(), v.end());
	int cnt = 0, ans = 0;

	if (!chk) {
		printf("0");
		return 0;
	}
	if (!f) {
		printf("1");
		return 0;
	}
	do {
		vector <int> cmp(v);
		for (int j = 0; j < v.size(); j++)cmp.push_back(v[j]);

		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = j; k < cmp.size(); k++) {
				sum += cmp[k];
				if (sum == 50) {
					cnt++;
					break;
				}
				else if (sum > 50)break;
			}
		}
		ans = max(ans, cnt);
		cnt = 0;
	} while (next_permutation(v.begin(), v.end()));
	printf("%d", ans / 2);
	return 0;
}
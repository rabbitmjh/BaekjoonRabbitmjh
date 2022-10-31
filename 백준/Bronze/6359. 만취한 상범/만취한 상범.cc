#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

int arr[105], ans[105];
int n, m, t;


int main() {
	std::ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 2; i <= 100; i++) {
		for (int j = i; j <= 100; j += i) {
			if (arr[j])arr[j] = 0;
			else arr[j] = 1;
		}
		for (int j = 1; j <= i; j++)
			if (!arr[j])ans[i]++;
	}
	while (t--) {
		cin >> n;
		cout << ans[n] << endl;
	}

	return 0;
}
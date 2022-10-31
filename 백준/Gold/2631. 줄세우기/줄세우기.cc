#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

vector <int> v;
int n, a, sum;
int arr[1005];
int dp[1005];

int main() {
	v.push_back(-1e9);
	cin >> n;	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (v.back() < a) {
			v.push_back(a);
			
		}
		else {
			auto find = lower_bound(v.begin(), v.end(), a);
			*find = a;
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}
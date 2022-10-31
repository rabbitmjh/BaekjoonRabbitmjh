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
int arr[45];
int main() {
	std::ios::sync_with_stdio(false);
	int n, ans=0;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		arr[n % 42]++;
	}
	for (int i = 0; i < 42; i++)if (arr[i])ans++;
	cout << ans;
	return 0;
}
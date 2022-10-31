#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int arr[100005];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n,greater<int>());
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(arr[i] + i + 1, ans);
	cout << ans + 1 << endl;

	return 0;
}
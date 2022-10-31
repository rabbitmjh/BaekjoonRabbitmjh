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

p arr[100005];
int n, m, t;


int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)cout << arr[i].second << " " << arr[i].first << "\n";

	return 0;
}
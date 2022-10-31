#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<string, p> pp;

int n;
pp arr[105];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;

	int low = -999999999, high = 999999999;
	for (int i = n - 1; i > -1; i--) {
		if(arr[i].first=="none"){
			low = max(low, arr[i].second.first);
			high = min(high, arr[i].second.second);
		}
		else if (arr[i].first == "off") {
			low += arr[i].second.first;
			high += arr[i].second.second;
		}
		else {
			low -= arr[i].second.second;
			high -= arr[i].second.first;
			low = max(0, low);
		}
	}
	printf("%d %d\n", low, high);

	low = -999999999, high = 999999999;
	for (int i = 0; i < n; i++) {
		if (arr[i].first == "none") {
			low = max(low, arr[i].second.first);
			high = min(high, arr[i].second.second);
		}
		else if (arr[i].first == "on") {
			low += arr[i].second.first;
			high += arr[i].second.second;
		}
		else {
			low -= arr[i].second.second;
			high -= arr[i].second.first;
			low = max(0, low);
		}
	}
	printf("%d %d\n", low, high);

	return 0;
}
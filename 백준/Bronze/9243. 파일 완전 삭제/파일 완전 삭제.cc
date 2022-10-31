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

int n;
int arr[1005], arr1[1005];
string s, s1;

int main() {
	cin >> n;
	cin >> s >> s1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')arr[i] = 0;
		else arr[i] = 1;
		if (s1[i] == '0')arr1[i] = 0;
		else arr1[i] = 1;
	}

	int cnt = 0, cnt1 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (abs(arr[i] - arr1[i]) == 1)cnt++;
		if (arr[i] == arr1[i])cnt1++;
	}

	if ((cnt1 == s.size() && n % 2 == 0) || (cnt == s.size() && n % 2 == 1))printf("Deletion succeeded");
	else printf("Deletion failed");
	return 0;
}
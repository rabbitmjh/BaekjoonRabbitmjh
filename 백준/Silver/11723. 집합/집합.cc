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

int n, x, arr[20];
string s;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "all")
			memset(arr, -1, sizeof(arr));
		else if (s == "empty")
			memset(arr, 0, sizeof(arr));
		else {
			cin >> x;
			if (s == "add")
				arr[x - 1] = -1;
			else if (s == "remove")
				arr[x - 1] = 0;
			else if (s == "check")
				cout << abs(arr[x - 1]) << "\n";
			else if (s == "toggle")
				if (!arr[x - 1])arr[x - 1] = -1;
				else arr[x - 1] = 0;
		}
	}

	return 0;
}
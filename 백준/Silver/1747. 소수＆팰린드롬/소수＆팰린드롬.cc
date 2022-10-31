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
typedef long double ld;
typedef pair<int, int> p;
int n, m, en;
int arr[1003005];

bool chk(int m) {
	string s = to_string(m);
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i])return false;
	}
	return true;
}

int main() {
	cin >> n;
	arr[1] = 1;
	for (int i = 2; i <= 1003001; i++) {
		if (arr[i])continue;
		for (int j = i * 2; j <= 1003001; j += i)
			arr[j] = 1;
	}

	for (int i = n; i <= 1003001; i++) {
		if (arr[i])continue;
		if (chk(i)) {
			printf("%d", i);
			return 0;
		}
	}

	return 0;
}

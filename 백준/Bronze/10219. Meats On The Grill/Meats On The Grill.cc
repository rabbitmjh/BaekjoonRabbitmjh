#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <string.h>
#include <utility>
using namespace std;
queue<pair<int, int>>q;

int t, n, m;

int main() {
	cin >> t;
	while (t--) {
		string s[11];
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> s[i];

		for (int i = n - 1; i >= 0; i--) {
			cout << s[i] << endl;
		}
	}
	return 0;
}
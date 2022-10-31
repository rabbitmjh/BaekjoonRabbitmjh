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

int n, cnt;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		if (i == 1 || i == n) {
			for (int j = 1;j <= n;j++)cout << "*";
			cout << "\n";
			continue;
		}
		else {
			for (int j = 1;j <= n;j++) {
				if (j == 1 || j == n)cout << "*";
				else if (j == i || j == n - i+1)cout << "*";
				else cout << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
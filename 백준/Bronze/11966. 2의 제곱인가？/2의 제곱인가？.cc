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

int n, sum;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i <= 30; i++) {
		if (n == pow(2, i)) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}
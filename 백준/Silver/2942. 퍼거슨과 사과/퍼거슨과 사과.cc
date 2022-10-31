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
int r, g;
bool check = false;
int gcd(int a, int b) {
	if (b) return gcd(b, a % b);
	else return a;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> g;
	if (g > r) {
		check = true;
		swap(r, g);
	}
	int num = gcd(r, g);

	for (int i = 1; i <= num; i++)
		if (r % i == 0 && g % i == 0) {
			if (check)
				cout << i << " " << g / i << " " << r / i;
			else
				cout << i << " " << r / i << " " << g / i;
			cout << endl;
		}

	return 0;
} 
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k;

int main() {
	FIO;
	cin >> n >> k;
	if (n <= k) {
		cout << "minigimbob";
		return 0;
	}

	int mod;
	while (k < n) {
		mod = n % 3;
		if (mod == 2)
			n--;
		else
			n = n / 3 * 2 + mod;

		if (k - 1 == 0) {
			cout << "water";
			return 0;
		}
		k--;
	}
	cout << "minigimbob";


	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, l;
ll a = -1, b = -1;

int main() {
	FIO;
	cin >> n >> l;
	for (int i = l; i <= 100; i++) {
		if (i % 2 == 0) {
			if (n % i == i / 2) {
				a = n / i - i / 2 + 1;
				b = n / i + i / 2;
				break;
			}
		}
		else {
			if (n % i == 0) {
				a = n / i - i / 2;
				b = n / i + i / 2;
				break;
			}
		}
	}

	if (a < 0)
		cout << -1;
	else {
		for (ll i = a; i <= b; i++)
			cout << i << " ";
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[1 << 20];

int main() {
	FIO;

	while (cin >> n) {
		int idx = 1 << (n % 32);
		if (arr[n / 32] & idx)
			continue;
		else {
			cout << n << " ";
			arr[n / 32] += idx;
		}
	}
	
	return 0;
}
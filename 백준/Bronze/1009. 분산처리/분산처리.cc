#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t;

int main() {
	FIO;
	cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		int tmp = 1;
		for (int i = 0; i < b; i++)
			tmp = (tmp * a) % 10;
		if (tmp == 0)tmp = 10;
		cout << tmp << "\n";
	}

	return 0;
}
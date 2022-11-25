#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int a, b, c;

int main() {
	FIO;
	cin >> a >> b >> c;

	if (a == b && b == c)
		cout << 10000 + a * 1000;
	else if (a == b)
		cout << 1000 + a * 100;
	else if (b == c)
		cout << 1000 + b * 100;
	else if (a == c)
		cout << 1000 + c * 100;
	else
		cout << max(a, max(b, c)) * 100;

	return 0;
}
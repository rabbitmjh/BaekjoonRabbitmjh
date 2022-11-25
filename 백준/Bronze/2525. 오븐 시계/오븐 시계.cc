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

	int n = b += c;
	b = n % 60;
	a += n / 60;
	if (a > 23)
		a -= 24;

	cout << a << " " << b;

	return 0;
}
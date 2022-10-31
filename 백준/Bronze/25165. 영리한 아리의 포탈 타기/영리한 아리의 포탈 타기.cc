#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, a, d, s1, s2;

int main() {
	FIO;
	cin >> n >> m >> a >> d >> s1 >> s2;

	if (s1 == 1 && s2 <= a && !d)cout << "NO...";
	else if (s1 == 1 && s2 < a && d)cout << "YES!";
	else if (s1 == 1 && s2 > a && !d)cout << "YES!";
	else if (s1 == 1 && s2 >= a && d)cout << "NO...";
	else if (s1 != n)cout << "NO...";

	else if (n % 2 == 1) {
		if (s1 == n && !d)cout << "YES!";
		else if (s1 == n && d)cout << "NO...";
	}
	else if (n % 2 == 0) {
		if (s1 == n && !d)cout << "NO...";
		else if (s1 == n && d)cout << "YES!";
	}
	return 0;
}

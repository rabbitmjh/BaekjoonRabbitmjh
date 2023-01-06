#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll a, b;

int main() {
	FIO;
	cin >> a >> b;
	cout << (a + b) * (a - b);

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
int n, m, k;
int main() {
	FIO;
	cin >> n >> m >> k;

	while (k < 0)
		k += n;

	int a = (m + k - 4) % n;

	cout << (a + n) % n + 1;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll arr[35][35];
ll dp(ll w, ll h) {
	if (h == -1)
		return 0;
	if (w == 0)
		return 1;
	if (arr[w][h])
		return arr[w][h];

	arr[w][h] = dp(w - 1, h + 1) + dp(w, h - 1);
	return arr[w][h];
}

int main() {
	FIO;
	int n;
	while (1) {
		cin >> n;
		if (!n)break;
		cout << dp(n, 0) << "\n";
	}

	return 0;
}
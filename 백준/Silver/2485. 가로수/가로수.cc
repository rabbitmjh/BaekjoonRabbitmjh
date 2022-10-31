#include <iostream>
#include <algorithm>
using namespace std;

int n;
int tree[100000], d[100000];

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> tree[i];
	sort(tree, tree + n);

	for (int i = 0; i < n; i++)
		d[i] = tree[i + 1] - tree[i];

	int dist = d[0];
	for (int i = 1; i < n - 1; i++)
		dist = gcd(dist, d[i]);

	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		ans += (d[i] / dist) - 1;
	cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, m, arr[10005], ans, l, r, sum;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	

	while (1) {
		if (sum >= m) {
			sum -= arr[l];
			l++;
		}
		else if (r == n)break;
		else {
			sum += arr[r];
			r++;
		}
		if (sum == m)ans++;
	}
			
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, n, m, arr[25], ans[10005];

int main() {
	FIO;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		cin >> m;

		ans[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = arr[i]; j <= m; j++)
				ans[j] += ans[j - arr[i]];
		
		cout << ans[m] << "\n";
		memset(ans, 0, sizeof(ans));
		memset(ans, 0, sizeof(arr));
	}
	return 0;
}
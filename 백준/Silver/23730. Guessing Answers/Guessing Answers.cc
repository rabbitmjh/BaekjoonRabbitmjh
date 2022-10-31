#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;
typedef pair<int, p> pp;

int n, m, arr[100005], ans[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	while (m--) {
		int a; cin >> a;
		ans[a] = arr[a];
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i])continue;
		
		//틀려야할때 처리
		for (int j = 1; j <= 5; j++) {
			if (ans[i + 1]) {
				if (ans[i - 1] != j && ans[i + 1] != j && arr[i] != j) {
					ans[i] = j;
					break;
				}
			}
			else {
				if (ans[i - 1] != j && arr[i] != j) {
					ans[i] = j;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";

	return 0;
}
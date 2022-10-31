#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[1000005], ans[1000005];

void go() {
	for (int i = n - 2; i > -1; i--) {
		int a = i, b = n - 1;
		int cnt = 0;

		while (arr[a] == arr[b]) {
			a--; b--;
			cnt++;
		}

		ans[cnt]++;
	}
}

int main() {
	FIO;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	go();
	for (int i = n - 1; i > 0; i--) {
		if (ans[i]) {
			cout << i << " " << ans[i];
			return 0;
		}
	}
	cout << -1;

	return 0;
}

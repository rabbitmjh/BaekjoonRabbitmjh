#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, ans, arr[55];

bool check() {
	int cnt = 0;
	for (int i = 1;i < n - 1;i++) {
		int now = arr[i - 1] + arr[i + 1];
		if (arr[i] * 2 > now) {
			ans += arr[i] - (now / 2);
			arr[i] = now / 2;
		}
		else cnt++;
	}
	if (cnt == n - 2)
		return true;
	else
		return false;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	
	if (n == 1 || n == 2) {
		cout << 0;
		return 0;
	}

	while (1) {
		bool chk = check();
		if (chk)break;
	}
	cout << ans;

	return 0;
}
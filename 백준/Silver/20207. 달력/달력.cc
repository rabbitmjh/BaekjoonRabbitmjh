#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<string, string> p;
typedef pair<int, p> pp;

int n, arr[366], st, en, h, ans;

int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s;j <= e;j++)
			arr[j]++;
	}

	for (int i = 1;i <= 365;i++) {
		if (arr[i]) {
			if (!st) {
				st = i;
				en = i;
			}
			else
				en = i;
			h = max(h, arr[i]);
		}
		else {
			ans += (en + 1 - st) * h;
			st = en = h = 0;
		}
	}
	ans += (en + 1 - st) * h;

	cout << ans;

	return 0;
}

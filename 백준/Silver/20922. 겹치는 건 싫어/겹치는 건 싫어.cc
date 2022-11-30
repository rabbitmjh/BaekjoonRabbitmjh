#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, arr[200005], cnt[100005], ans, l;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;

		while (cnt[arr[i]] > m)
			cnt[arr[l++]]--;
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll t, n, ans, arr[100002];
stack <ll> st;

int main() {
	FIO;
	while (1) {
		cin >> t;
		if (!t)break;
		//cin >> n;
		n = t;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		st.push(0);
		for (int i = 1; i <= n + 1; i++) {
			while (!st.empty() && arr[st.top()] > arr[i]) {
				int tmp = st.top();

				st.pop();
				int garo = i - st.top() - 1;
				int now = arr[tmp] * garo;
				ans = max(ans, arr[tmp] * garo);
			}
			st.push(i);
		}
		cout << ans << "\n";

		memset(arr, 0, sizeof(arr));
		ans = 0;
		while (!st.empty())
			st.pop();
	}
	return 0;
}
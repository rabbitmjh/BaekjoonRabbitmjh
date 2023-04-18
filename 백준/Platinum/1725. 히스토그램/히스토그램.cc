#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans, arr[100002];
stack <int> st;

int main() {
	FIO;
	cin >> n;
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
	cout << ans;
	return 0;
}
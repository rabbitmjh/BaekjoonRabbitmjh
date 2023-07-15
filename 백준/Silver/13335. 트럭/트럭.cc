#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, w, l, ans, sum, arr[1005];
queue <int> q;
queue <p> b;

int main() {
	FIO;
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}
			if (arr[i] + sum <= l)
				break;
			q.push(0);
			ans++;
		}
		q.push(arr[i]);
		sum += arr[i];
		ans++;
	}

	cout << ans + w;

	return 0;
}
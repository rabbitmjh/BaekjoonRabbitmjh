#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans[55];
p arr[55];

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		ans[arr[i].second] = i;
	
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";

	return 0;
}
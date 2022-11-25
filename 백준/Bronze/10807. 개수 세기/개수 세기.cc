#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[105], v, cnt;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> v;

	for (int i = 0; i < n; i++)
		if (arr[i] == v)
			cnt++;

	cout << cnt;

	return 0;
}
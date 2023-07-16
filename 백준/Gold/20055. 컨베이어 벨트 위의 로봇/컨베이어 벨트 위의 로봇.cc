#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k, arr[205], robot[105], ans = 1;


int main() {
	FIO;
	cin >> n >> k;
	for (int i = 1; i <= n * 2; i++)
		cin >> arr[i];

	while (1) {
		for (int i = n; i >= 2; i--)
			robot[i] = robot[i - 1];
		robot[1] = robot[n] = 0;

		int tmp = arr[2 * n];
		for (int i = n * 2; i >= 2; i--)
			arr[i] = arr[i - 1];
		arr[1] = tmp;

		for (int i = n - 1; i >= 2; i--) {
			if (robot[i] && !robot[i + 1] && arr[i + 1] >= 1) {
				arr[i + 1]--;
				robot[i] = 0;
				if (i + 1 != n)
					robot[i + 1] = 1;
			}
		}

		if (arr[1] > 0) {
			robot[1] = 1;
			arr[1]--;
		}
		int cnt = 0;
		for (int i = 1; i <= 2 * n; i++)
			if (!arr[i])
				cnt++;
		if (cnt >= k)
			break;
		ans++;
	}
	cout << ans;

	return 0;
}
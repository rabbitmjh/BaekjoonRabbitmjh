#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n;
vector <int> v, ans, arr;


int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;cin >> a;
		v.push_back(a);
		ans.push_back(a);
	}
	for (int i = 0;i < n;i++)
		arr.push_back(pow(2, i));

	sort(v.begin(), v.end());
	int m = pow(2, n);

	for (int i = 1;i <= m;i++) {
		int a = i, b = n, sum = 0;

		while (a && b) {
			if (a - arr[b - 1] < 0) {
				b--;
			}
			else {
				sum += v[b - 1];
				a -= arr[b - 1];
				b--;
			}
		}
		ans.push_back(sum);
	}

	sort(ans.begin(), ans.end());
	if (ans.front() != 1) {
		cout << 1;
		return 0;
	}

	for (int i = 1;i < ans.size();i++) {
		if (ans[i] - ans[i - 1] == 1)continue;
		else if (ans[i] == ans[i - 1])continue;
		else {
			cout << ans[i - 1] + 1;
			return 0;
		}
	}
	cout << ans.back() + 1;

	return 0;
}
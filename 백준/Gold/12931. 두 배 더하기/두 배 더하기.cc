#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, arr[55], cmp[55], ans, tmp[55];
bool check = true;

bool compare() {
	for (int i = 0;i < n;i++)
		if (arr[i] != cmp[i])
			return false;
	return true;
}


int main() { 
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	while (!compare()) {
		for (int i = 0;i < n;i++) {
			if (arr[i] % 2 == 1) {
				arr[i]--;
				ans++;
				check = false;
			}
		}

		if (check) {
			for (int i = 0;i < n;i++)
				arr[i] /= 2;
			ans++;
		}
		check = true;
	}
	
	cout << ans;

	return 0;
}

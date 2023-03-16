#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, arr[15], under, uremain, sum;
vector <string> v;

int main() {
	FIO;
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		string a; cin >> a;
		v.push_back(a);
		if (a[0] >= 'a')
			arr[i] = 1;
		sum += a.size();
	}

	under = (m - sum) / (n - 1);
	uremain = (m - sum) % (n - 1);
	
	cout << v[0];
	for (int i = 1;i < n;i++) {
		if (arr[i] && uremain) {
			for (int j = 0;j <= under;j++)
				cout << "_";
			uremain--;
		}
		else {
			for (int j = 0;j < under;j++)
				cout << "_";
			if (n - i <= uremain) {
				cout << "_";
				uremain--;
			}
		}
		cout << v[i];
	}

	return 0;
}
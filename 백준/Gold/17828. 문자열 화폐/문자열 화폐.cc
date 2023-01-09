#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<string, string> p;
typedef pair<int, p> pp;

int n, x, cur;
string ans;

int main() {
	FIO;
	cin >> n >> x;
	if (x - n * 26 > 0 || n > x) {
		cout << "!" << endl;
		return 0;
	}
	cur = x;

	for (int i = 1;i <= n;i++) {
		int num = 26 * (n - i);
		if (cur - num < 0) {
			ans.push_back('A');
			cur--;
		}
		else {
			ans.push_back('A' + cur - num - 1);
			cur -= (cur - num);
		}
	}

	cout << ans;

	return 0;
}

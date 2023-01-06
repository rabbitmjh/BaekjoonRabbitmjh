#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
//typedef pair<int, int> p;
//typedef pair<int, p> pp;

int ans, p, k;
string s;

int main() {
	FIO;
	cin >> s;
	
	for (int i = 0;i < s.size();i++) {
		int next = s[i];

		if (next == 'P') {
			p++;
			if (k > 0)k--;
			else ans++;
		}
		else {
			k++;
			if (p > 0)p--;
			else ans++;
		}
	}

	cout << ans;
	return 0;
}

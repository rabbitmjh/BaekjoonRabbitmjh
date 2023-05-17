#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;
bool go(int l, int r, string s) {
	while (l < r) {
		if (s[l] == s[r]) {
			l++;
			r--;
		}
		else 
			return false;
	}
	return true;
}
int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string s;cin >> s;

		int l = 0, r = s.size() - 1;

		bool check = true;//회문이면 true = 0 아니면 false = 2
		bool pseudo = false;//유사회문 = 1
		while (l < r) {
			if (s[l] == s[r]) {
				l++;
				r--;
			}
			else {
				if (go(l + 1, r, s) || go(l, r - 1, s)) {
					pseudo = true;
					check = false;
				}
				else {
					pseudo = false;
					check = false;
				}
				break;
			}
		}
		if (check)cout << 0 << "\n";
		else if (pseudo)cout << 1 << "\n";
		else cout << 2 << "\n";
	}

	return 0;
}
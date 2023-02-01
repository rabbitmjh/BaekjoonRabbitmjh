#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string s1, s2;
int ans;

int main() {
	FIO;
	cin >> s1 >> s2;
	for (int i = 0;i < s2.size();i++) {
		string tmp;
		tmp.push_back(s2[i]);
		while (1) {
			if (s1.find(tmp) != string::npos) {
				i++;
				tmp.push_back(s2[i]);
			}
			else {
				ans++;
				i--;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
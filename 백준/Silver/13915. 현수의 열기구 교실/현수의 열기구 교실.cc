#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;

int main() {
	FIO;

	while (cin >> n) {
		set <string> st;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			string tmp = "0000000000";
			for (int j = 0; j < s.size(); j++) 
				tmp[s[j] - '0'] = '1';
			st.insert(tmp);
		}
		cout << st.size() << endl;
	}
	
	return 0;
}
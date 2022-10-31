#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

set <string> st;
string s, cmp;

int main() {
	FIO;
	cin >> s;


	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			cmp.push_back(s[j]);
			st.insert(cmp);
		}
		cmp.clear();
	}

	cout << st.size();

	return 0;
}
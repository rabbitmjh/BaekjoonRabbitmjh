#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string s, result;
vector <string> v;
int clen;

int main() {
	FIO;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':')
			clen++;
	}
	clen = abs(9 - clen - 1);
	if (s[0] == s[1] && s[1] == ':')
		clen++;
	else if (s[s.size() - 1] == s[s.size() - 2] && s.back() == ':')
		clen++;

	string tmp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':' && s[i + 1] == ':') {
			if (!tmp.empty()) {
				v.push_back(tmp);
				tmp.clear();
			}
			v.push_back("zzzz");
		}
		if (s[i] == ':' && !tmp.empty()) {
			v.push_back(tmp);
			tmp.clear();
		}
		else if (s[i] != ':')
			tmp.push_back(s[i]);
	}
	if (!tmp.empty())
		v.push_back(tmp);

	for (int i = 0; i < v.size(); i++) {
		bool chk = false;
		if (v[i] == "zzzz") {
			for (int j = 0; j < clen; j++) {
				result += "0000:";
			}
			chk = true;
		}
		if (v[i].size() < 4) {
			int zero = 4 - v[i].size();
			for (int j = 0; j < zero; j++)
				result += '0';
		}
		if (!chk) {
			result += v[i];
			result += ":";
		}
	}

	result.pop_back();
	cout << result;
	return 0;
}
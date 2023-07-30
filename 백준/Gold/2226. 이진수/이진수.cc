#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;
string sO, sE, ans = "1";

string minS(string a, string b) {
	string ret;
	int q = a.size();
	int w = b.size();
	int maxLength = max(q, w);
	a = string(maxLength - q, '0') + a;
	b = string(maxLength - w, '0') + b;

	int tmp = 0;
	for (int i = maxLength - 1;i > -1;i--) {
		int digit1 = a[i] - '0';
		int digit2 = b[i] - '0';

		digit1 -= tmp;

		if (digit1 < digit2) {
			digit1 += 10;
			tmp = 1;
		}
		else {
			tmp = 0;
		}

		int diff = digit1 - digit2;
		ret = to_string(diff) + ret;
	}

	return ret;
}
string pluS(string a, string b) {
	string ret;
	int q = a.size();
	int w = b.size();
	int maxLength = max(q, w);
	a = string(maxLength - q, '0') + a;
	b = string(maxLength - w, '0') + b;

	int tmp = 0;
	for (int i = maxLength - 1;i > -1;i--) {
		int digit1 = a[i] - '0';
		int digit2 = b[i] - '0';
		int sum = digit1 + digit2 + tmp;

		tmp = sum / 10;
		sum %= 10;

		ret = to_string(sum) + ret;
	}

	if (tmp > 0)
		ret = to_string(tmp) + ret;

	return ret;
}

string mulS(string s, int chk) {
	string ret = "0";
	int cnt = 1;
	for (int i = s.size() - 1;i > -1;i--) {
		string tmp = to_string((s[i] - '0') * 4);
		for (int j = 1;j < cnt;j++)
			tmp.push_back('0');
		ret = pluS(tmp, ret);
		cnt++;
	}

	if (chk == 1)
		ret = pluS(ret, "1");
	else
		ret = minS(ret, "1");

	return ret;
}

int main() {
	FIO;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	sO = sE = "1";
	for (int i = 4;i <= n;i++) {
		if (i % 2 == 0) {
			sE = mulS(sE, 0);
			ans = sE;
		}
		else {
			sO = mulS(sO, 1);
			ans = sO;
		}
	}

	cout << ans;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string s1, s2;
int cnt1, cnt2;

int main() {
	FIO;
	cin >> s1 >> s2;

	for (int i = 0;i < s1.size();i++) {
		if (s1[i] != 'a')break;
		cnt1++;
	}
	for (int i = 0;i < s2.size();i++) {
		if (s2[i] != 'a')break;
		cnt2++;
	}

	if (cnt1 >= cnt2)cout << "go";
	else cout << "no";
	return 0;
}

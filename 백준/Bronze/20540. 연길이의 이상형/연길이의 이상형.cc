#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string mbti, ans;

int main() {
	FIO;
	cin >> mbti;
	if (mbti[0] == 'I')
		ans.push_back('E');
	else
		ans.push_back('I');

	if (mbti[1] == 'S')
		ans.push_back('N');
	else
		ans.push_back('S');

	if (mbti[2] == 'T')
		ans.push_back('F');
	else
		ans.push_back('T');

	if (mbti[3] == 'J')
		ans.push_back('P');
	else
		ans.push_back('J');

	cout << ans;
	return 0;
}
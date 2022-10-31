#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;
string s;

int main() {
	FIO;
	cin >> n >> s;
	char a = s[s.size() - 1];
	if (a == 'r' || a == 's' || a == 'e' || a == 'f' || a == 'a' || a == 'q' || a == 't' || a == 'd' || a == 'w' || a == 'c' || a == 'z' || a == 'x' || a == 'v' || a == 'g')
		cout << 1;
	else cout << 0;

	return 0;
}
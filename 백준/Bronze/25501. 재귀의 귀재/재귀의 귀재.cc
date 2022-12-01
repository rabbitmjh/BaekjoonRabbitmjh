#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, cnt;
string s; 

int recursion(int l, int r) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(l + 1, r - 1);
}

int isPalindrome() {
	return recursion(0, s.size() - 1);
}
int main() {
	FIO;
	cin >> n;
	while (n--) {
		cin >> s;
		cout << isPalindrome() << " " << cnt << "\n";
		cnt = 0;
	}
	
	return 0;
}
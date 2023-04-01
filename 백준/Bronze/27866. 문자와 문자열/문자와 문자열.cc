#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;
string s;

int main() {
	FIO;
	cin >> s >> n;
	cout << s[n - 1];
	
	return 0;
}
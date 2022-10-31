#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp; 

int num = 1000000;
string s;
int arr[5005];

int main() {
	FIO;
	cin >> s;

	if (s[0] == '0') {
		cout << 0;
		return 0;
	}
	else if (s.size() == 1) {
		cout << 1;
		return 0;
	}
	arr[0] = 1;

	if (s[1] == '0') {
		if (s[0] == '1' || s[0] == '2')
			arr[1] = 1;
		else {
			cout << 0;
			return 0;
		}
	}
	else {
		if (s[0] == '1')
			arr[1] = 2;
		else if (s[0] == '2' && s[1] < '7')
			arr[1] = 2;
		else
			arr[1] = 1;
	}


	if (s.size() == 2) {
		cout << arr[1];
		return 0;
	}
	for (int i = 2;i < s.size();i++) {
		if (s[i] == '0' && !(s[i - 1] == '1' || s[i - 1] == '2')) {
			cout << 0;
			return 0;
		}
		else if (s[i] == '0' && (s[i - 1] == '1' || s[i - 1] == '2'))
			arr[i] = (arr[i]+arr[i - 2])%num;
		else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
			arr[i] = (arr[i - 1]+arr[i - 2]) % num;
		else
			arr[i] = (arr[i]+arr[i - 1])%num;
	}
	cout << arr[s.size() - 1] % num;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m = 1, cnt, num;
vector <char> v;
bool check;

int main() {
	FIO;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	if (n < 0) {
		n *= -1;
		check = true;
	}

	while (m <= n) {
		m *= 3;
		cnt++;
	}
	m /= 3;
	cnt--;


	while (n) {
		if (n % 3 == 2) {
			n = n / 3 + 1;
			v.push_back('T');
		}
		else if(n % 3 == 1){
			v.push_back('1');
			n /= 3;
		}
		else {
			v.push_back('0');
			n /= 3;
		}
	}

	if (check) {
		for (int i = v.size() - 1; i > -1; i--) {
			if (v[i] == '1')cout << 'T';
			else if (v[i] == 'T')cout << '1';
			else cout << '0';
		}
	}
	else
		for (int i = v.size() - 1; i > -1; i--)
			cout << v[i];

	return 0;
}

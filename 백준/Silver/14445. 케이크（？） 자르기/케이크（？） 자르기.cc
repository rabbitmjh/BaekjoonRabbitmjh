#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n;

int main(){
	FIO;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n % 2 == 0)
		cout << n / 2;
	else
		cout << n / 2 + 1;
	return 0;
}


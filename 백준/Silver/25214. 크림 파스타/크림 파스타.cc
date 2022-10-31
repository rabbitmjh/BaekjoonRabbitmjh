#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp; 

int n, mn, mx, tmp;


int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int num; cin >> num;
		if (i == 0)
			mn = num;
		if (num - mn > tmp)
			tmp = num - mn;
		if (mn > num)
			mn = num;

		cout << tmp << " ";
	}
	return 0;
}
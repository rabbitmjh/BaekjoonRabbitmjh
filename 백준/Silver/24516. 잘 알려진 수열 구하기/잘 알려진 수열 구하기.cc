#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, num = 1;


int main() {
	FIO;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << num << " ";
		num += 2;
	}

	return 0;
}
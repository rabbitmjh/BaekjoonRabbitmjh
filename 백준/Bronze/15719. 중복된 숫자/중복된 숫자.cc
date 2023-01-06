#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, sum, ans;
vector <int> v;

int main() {
	FIO;
	cin >> n;
	
	for (int i = 1;i <= n;i++) {
		int a;cin >> a;
		ans += a;
		sum += i;
	}

	cout << n - (sum - ans);
	return 0;
}

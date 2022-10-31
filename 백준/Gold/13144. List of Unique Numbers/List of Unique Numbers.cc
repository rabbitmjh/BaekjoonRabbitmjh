#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, l, r, arr[100005];
ll ans;
vector <int> v;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	
	for (int i = 0; i < n; i++) {
		l = i;
		while (r < n) {
			if (arr[v[r]])
				break;
			arr[v[r]]++;
			r++;
		}
		ans += r - l;
		arr[v[l]] = 0;
	}

	cout << ans << endl;
	return 0;
}
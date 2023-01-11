#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n;
vector <int> v;

int main() {
	FIO;
	
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(),greater<>());
	for (int i = 0;i < v.size();i++)
		cout << v[i] << "\n";
	return 0;
}

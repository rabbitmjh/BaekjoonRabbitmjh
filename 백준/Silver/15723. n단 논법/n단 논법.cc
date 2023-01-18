#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, m, arr[30][30];
vector <int> v[30], v2;

void go(vector <int> v2, int num) {
	v2.push_back(num);
	for (int i = 0;i < v[num].size();i++) {
		for (int j = 0;j < v2.size();j++) {
			if (arr[v2[j]][v[num][i]] && v2.size() > 1)continue;
			arr[v2[j]][v[num][i]] = 1;
			go(v2, v[num][i]);
		}
	}
	v2.pop_back();
	return;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		char a, b;cin >> a;
		string s;cin >> s;
		cin >> b;

		arr[a - 'a'][b - 'a'] = 1;
		v[a - 'a'].push_back(b - 'a');
	}

	for (int i = 0;i < 26; i++) {
		if (v[i].size() > 0)
			go(v2, i);
	}

	cin >> m;
	for (int i = 0;i < m;i++) {
		char a, b;cin >> a;
		string s;cin >> s;
		cin >> b;

		if (arr[a - 'a'][b - 'a'])cout << "T\n";
		else if (a == b)cout << "T\n";
		else cout << "F\n";
	}



	return 0;
}
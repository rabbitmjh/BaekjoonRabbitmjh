#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, arr[10005];
vector <int> alp[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (alp[s[j] - 'a'].empty())
				alp[s[j] - 'a'].push_back(i);
			else if (alp[s[j] - 'a'].back() != i)
				alp[s[j] - 'a'].push_back(i);
		}
	}
	for (int i = 0; i < m; i++) {
		int o, cnt = 0; char x;
		cin >> o >> x;
		if (o == 1) {
			for (int j = 0; j < alp[x - 'a'].size(); j++)
				arr[alp[x - 'a'][j]]++;
		}
		else {
			for (int j = 0; j < alp[x - 'a'].size(); j++) {
				if (arr[alp[x - 'a'][j]])
					arr[alp[x - 'a'][j]]--;
			}
		}
		for (int j = 0; j < n; j++)
			if (!arr[j])cnt++;
		cout << cnt << "\n";
	}


	return 0;
}
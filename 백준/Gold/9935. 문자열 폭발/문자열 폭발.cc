#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long  long ll;
typedef long double ld;
typedef pair<int, int> p;
string s, bomb, ans;
bool chk;
int main() {
	cin >> s >> bomb;
	
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		chk = true;
		int m = i - cnt;
		ans.push_back(s[i]);
		for (int j = bomb.size() - 1; j > -1; j--) {
			if (ans[m--] != bomb[j]) {
				chk = false;
				break;
			}
		}
		if (chk)for (int j = 0; j < bomb.size(); j++) {
			ans.pop_back();
			cnt++;
		}
	}
	if (ans.empty())printf("FRULA");
	else cout << ans;
	return 0;
}

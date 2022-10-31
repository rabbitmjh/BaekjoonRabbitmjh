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
#define mod 1000000007
int t;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		ll ans = 1, st = -5, cnt = 0;
		bool check = true;//유효한 ?인지(끝이면 false)

		for (int i = 0; i < s.size(); i++) {
			if (i == 0 && s[i] == '?') {
				st = 0;
				check = false;
				continue;
			}
			if (s[i] == '?') {
				if (s[i - 1] != '?') {
					st = i;
					cnt++;
				}
				else {
					cnt++;
				}
			}
			else {
				if (i == 0)continue;
				
				if (s[i - 1] == '?' && check) {//유효한 ?일때
					if (s[st - 1] != s[i]) {//?의 첫과 끝이 다른지
						ans = ans % mod * (cnt % mod + 1) % mod;
						cnt = 0;
						st = -5;
					}
					else {
						cnt = 0;
						st = -5;
						check = true;
					}
				}
				else {//유효한 ?가 아닐때
					cnt = 0;
					st = -5;
					check = true;
				}
			}
		}


		cout << ans << "\n";
	}

	return 0;
}
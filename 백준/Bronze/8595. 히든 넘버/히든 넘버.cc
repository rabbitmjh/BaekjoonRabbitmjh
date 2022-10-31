#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
string s;
ll ans;

int main() {
	cin >> n >> s;
	
	for (int i = s.size() - 1; i >= 0; i--) {
		ll sum = 0;
		int cnt = 0;
		while (48 <= s[i] && s[i] <= 57) {
			sum += pow(10, cnt)*(s[i] - 48);
			cnt++;
			i--;
		}
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}
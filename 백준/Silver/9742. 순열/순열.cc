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

string s, ans;
int n;
int arr[11] = { 0,1,2,6,24,120,720,5040,40320,362880,3628800 };//팩토리얼

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while (cin >> s >> n) {	
		if (n > arr[s.size()]) {//범위 밖인지
			cout << s << " " << n << " = " << "No permutation" << endl;
			continue;
		}

		ans = s;
		int c = 1;
		while (c != n) {
			next_permutation(ans.begin(),ans.end());
			c++;
		}


		cout << s << " " << n << " = " << ans << endl;
	}

	return 0;
}
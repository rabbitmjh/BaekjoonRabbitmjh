#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
typedef pair <int, p> pp;
//백준15829 Hashing

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; string s;
	cin >> n >> s;
	
	ll ans = 0, r = 31, m = 1234567891, sum = 1;

	for(int i = 0; i < s.size(); i++){
		int alp = s[i] - 'a' + 1;
		ans += sum * alp % m;
		sum = sum * r % m;
	}
	cout << ans % m;
	
    return 0;
}
//50 zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
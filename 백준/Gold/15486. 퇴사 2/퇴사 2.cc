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

ll n, arr[2][1500005], sum[1500005];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[0][i] >> arr[1][i];
	
	for (int i = 1; i <= n; i++) {
		ll nextT = arr[0][i];
		ll nextP = arr[1][i];
        
        sum[i + nextT] = max(sum[i + nextT], sum[i] + nextP);
        sum[i + 1] = max(sum[i + 1], sum[i]);
	}
	cout << sum[n + 1];

	return 0;
}
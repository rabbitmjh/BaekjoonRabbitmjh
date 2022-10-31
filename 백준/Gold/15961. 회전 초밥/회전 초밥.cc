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

int n, d, k, c, sum, ans, arr[3000005], check[3005];
int st, en;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < k; i++) {
		if (!check[arr[i]])
			sum++;
		check[arr[i]]++;
	}

	ans = sum;
	en = k;

	while (en < n + k) {
		//앞의 번호 빼줌
		check[arr[st % n]]--;
		if (!check[arr[st % n]])sum--;

		//뒤의 번호 더해줌
		if (!check[arr[en % n]])sum++;
		check[arr[en % n]]++;

		if (check[c])
			ans = max(ans, sum);
		else
			ans = max(ans, sum + 1);

		st++;
		en++;
	}
	cout << ans;

	return 0;
}
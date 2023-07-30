#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k;
int dp[25][2];
vector <p> v;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1e9;
		dp[i][1] = 1e9;
	}
	v.push_back({ 0,0 });
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;//a 작은점프 b 큰 점프
		v.push_back({ a,b });
	}
	cin >> k;
	
	//매우 큰 점프는 딱 한번, k만큼 에너지 소비
	dp[1][0] = 0;
	dp[2][0] = v[1].first;
	dp[3][0] = min(v[1].first + v[2].first, v[1].second);
	for (int i = 4; i <= n; i++) {
		dp[i][0] = min(v[i - 1].first + dp[i - 1][0], v[i - 2].second + dp[i - 2][0]);
		dp[i][1] = min(min(v[i - 1].first + dp[i - 1][1], v[i - 2].second + dp[i - 2][1]), k + dp[i - 3][0]);
	}
	cout << min(dp[n][0], dp[n][1]);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string a, b;
int dp[1005][1005];

int main() {
	FIO;
	cin >> a >> b;
	for (int i = 0;i <= a.size();i++)
		dp[i][0] = i;
	for (int j = 0;j <= b.size();j++)
		dp[0][j] = j;

	for (int i = 1;i <= a.size();i++) {
		for (int j = 1;j <= b.size();j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			//dp[i-1][j] : a에서 한 문자를 삭제한 경우
			//dp[i][j-1] : b에서 한 문자를 삽입한 경우
			//dp[i-1][j-1] : a와 b의 해당 문자를 대체한 경우
		}
	}
	

	cout << dp[a.size()][b.size()];

	return 0;
}
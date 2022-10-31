#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp; 

int n;
p arr[100005];
ll sum, cnt;

int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
	}
	sort(arr, arr + n);
	
	for (int i = 0;i < n;i++) {
		cnt += arr[i].second;

		if (sum <= cnt * 2) {
			cout << arr[i].first;
			break;
		}
	}
	return 0;
}
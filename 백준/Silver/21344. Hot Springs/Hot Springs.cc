#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, cnt = 1, i, arr[100005];

int main() {
	FIO;
	cin >> n; 

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	sort(arr + 1, arr + n + 1);
	if (n % 2 == 0) {//짝수일 때
		while (cnt <= n) {
			if (cnt % 2 == 1) {
				int cur = n / 2 - i;
				cout << arr[cur] << " ";
			}
			else {
				i++;
				int cur = n / 2 + i;
				cout << arr[cur] << " ";
			}
			cnt++;
		}
	}
	else {
		while (cnt <= n) {//홀수일 때
			if (cnt % 2 == 1) {	
				int cur = (n / 2 + 1) + i;
				cout << arr[cur] << " ";
			}
			else {
				i++;
				int cur = (n / 2 + 1) - i;
				cout << arr[cur] << " ";
			}
			cnt++;
		}
	}
	
	return 0;
}
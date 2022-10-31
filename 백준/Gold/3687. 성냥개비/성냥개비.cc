#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, t, arr[15] = { 0,0,0,0,0,0,0,0,10,18,22,20,28,68,88};
ll ans;
vector <p> v, w;

int main(){
	FIO;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> n;

		int m = n, cnt;
		if (m % 2 == 1) {
			m -= 3;
			a.append("7");
			while (m > 0) {
				m -= 2;
				a.append("1");
			}
		}
		else {
			while (m > 0) {
				m -= 2;
				a.append("1");
			}
		}

		if (n < 15) {
			if (n == 2)b.append("1");
			else if (n == 3)b.append("7");
			else if (n == 4)b.append("4");
			else if (n == 5)b.append("2");
			else if (n == 6)b.append("6");
			else if (n == 7)b.append("8");
			else if (n == 8)b.append(to_string(arr[n]));
			else if (n == 9)b.append(to_string(arr[n]));
			else if (n == 10)b.append(to_string(arr[n]));
			else if (n == 11)b.append(to_string(arr[n]));
			else if (n == 12)b.append(to_string(arr[n]));
			else if (n == 13)b.append(to_string(arr[n]));
			else if (n == 14)b.append(to_string(arr[n]));
		}
		else {
			if (n % 7 == 0) {
				while (n > 0) {
					b.append("8");
					n -= 7;
				}
			}
			else { 
				bool check = false;
				int num = n % 7;

				int c = num + 7;
				cnt = (n - c) / 7;

				b = to_string(arr[c]);
				while (cnt--)
					b.append("8");
			}
		}
		if (b.size() > 2) {
			if (b[1] == '2' && b[2] == '8')
				b[1] = b[2] = '0';
		}
		cout << b << " " << a << "\n";
	}
	return 0;
}
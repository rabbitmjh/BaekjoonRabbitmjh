#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<double, double> p;
typedef pair<int, p> pp;

bool friday = false;
int n;
vector <int> v, sum, sum1;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		if (a % 7 == 4)
			friday = true;
	}
	//sort(v.begin(), v.end());

	sum.push_back(v.front());

	for (int i = 1; i < v.size(); i++) {
		if (sum.empty()) {
			for (int j = 0; j < sum1.size(); j++) {
				sum.push_back(sum1[j] + v[i]);
				if (sum.back() % 7 == 4) {
					friday = true;
					break;
				}
			}
			for (int j = 0; j <= i; j++)
				sum.push_back(v[j]);
			
			sum1.clear();
		}
		else if (sum1.empty()) {
			for (int j = 0; j < sum.size(); j++) {
				sum1.push_back(sum[j] + v[i]);
				if (sum1.back() % 7 == 4) {
					friday = true;
					break;
				}
			}
			for (int j = 0; j <= i; j++)
				sum1.push_back(v[j]);
			sum.clear();
		}
	}
	if (friday)cout << "YES";
	else cout << "NO";
	return 0;
}
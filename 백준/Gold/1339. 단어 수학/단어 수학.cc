#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>
#include <string>
#include <limits.h>
using namespace std;
typedef long long ll;

int n,siz;
int arr[28];
int alp[28];
string s;
vector <string> v;

int main() {
	cin >> n;
	for(int j=0;j<n;j++) {
		cin >> s;
		v.push_back(s);
		//int b = 10;
		for (int i = 0; i < s.size(); i++) {
			int t = 1,a=s.size()-i;
			while (a--)t *= 10;
			t/=10;
			//t += b;
			alp[s[i]-65] += t;	
			//b--;
		}
	}

	int c = 9;
	for (c; c > 0; c--) {
		int sum = 0,a=0;
		bool check = false;
		for (int i = 0; i <= 26; i++) {
			if (sum < alp[i]) {
				sum = alp[i];
				a = i;
				check = true;
			}
		}
		if (check == true) {
			alp[a] = 0;
			arr[a] = c;
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int t = 1, a = v[i].size() - j;
			while (a--)t *= 10;
			t /= 10;
			sum += arr[v[i][j]-65] * t;
		}
	}
	printf("%d", sum);
	return 0;
}
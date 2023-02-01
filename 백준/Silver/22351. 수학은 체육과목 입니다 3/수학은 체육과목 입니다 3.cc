#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string s;
vector <int> v;

int main() {
	FIO;
	cin >> s;
	for (int i = 0;i < s.size();i++)
		v.push_back(s[i] - '0');
	
	for (int i = 1;i <= v.size();i++) {
		bool flag = true;
		int j = 0, pastNum = 0, firstNum, w = i;
		while (j < v.size()) {
			if (!pastNum) {
				for (int k = 1;k <= w;k++) {
					if (j >= v.size()) {
						flag = false;
						break;
					}
					pastNum += pow(10, w - k) * v[j];
					j++;
				}
				firstNum = pastNum;
			}
			else {
				int curNum = 0;
				if (pastNum % 10 == 9) {
					int tmp = pastNum, check = 1;
					while (tmp) {
						if (tmp % 10 == 9)
							tmp /= 10;
						else {
							check = 0;
							break;
						}
					}
					if (check)w++;
				}
				for (int k = 1;k <= w;k++) {
					if (j >= v.size()) {
						flag = false;
						break;
					}
					curNum += pow(10, w - k) * v[j];
					j++;
				}

				if (pastNum + 1 == curNum)
					pastNum = curNum;
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag) {
			cout << firstNum << " " << pastNum;
			break;
		}
	}

	return 0;
}
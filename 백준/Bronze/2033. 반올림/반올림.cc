#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

string n = "0", s;
int main() {
	cin >> s;
	n.append(s);
	bool check = true;
	int cmp1 = stoi(n), cmp2;
	if (cmp1 < 10) {
		printf("%d", cmp1);
		return 0;
	}
	for (int i = s.size(); i >= 1; i--) {
		cmp2 = pow(10, s.size() - i + 1);
		if (cmp1 <= cmp2)check = false;
		if (check == false)break;
		
		if (n[i] >= 53) {
			n[i] = '0';
			n[i - 1] = n[i - 1] + 1;
			cmp1 = stoi(n);
			if (n[i - 1]==':') {
				cmp1 += pow(10, n.size() - i + 1);
			}
		}
		else n[i] = '0';
	}
	if (stoi(n)>0)cmp1 = stoi(n);
	cout << cmp1;
	return 0;
}
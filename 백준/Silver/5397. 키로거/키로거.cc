#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <string>
using namespace std;

int num;

int main() {
	scanf("%d", &num);
	while (num--) {
		deque <char> q;

		string str;
		int cnt1 = 0;
		int cnt2 = 0;
		char a;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (cnt1 >= q.size()) {
					continue;
				}
				if (q.empty()) {
					continue;
				}
				else {
					cnt1++;
					a = q.back();
					q.push_front(a);
					q.pop_back();
				}
			}
			else if (str[i] == '>') {
				cnt2++;
				if (q.empty()) {
					continue;
				}
				else if (cnt1 != 0) {
					cnt1--;
					a = q.front();
					q.pop_front();
					q.push_back(a);
				}
				else continue;
			}
			else if (str[i] == '-') {
				if (q.size() <= cnt1) continue;
				if (!q.empty()) {
					q.pop_back();
				}
				else {
					continue;
				}
			}
			else {
				q.push_back(str[i]);
			}



		}
		while (cnt1--) {
			a = q.front();
			q.pop_front();
			q.push_back(a);
		}
		for (int i = 0; i < q.size(); i++) {
			cout << q[i];
		}
		printf("\n");

	}
}
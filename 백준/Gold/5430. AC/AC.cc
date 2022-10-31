#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <string>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int n, m, t;

int main() {
	scanf("%d", &t);
	while (t--) {
		string s, num;
		deque <int> dq;
		cin >> s;
		cin >> n;
		cin >> num;
		int temp = 0, error = 0;
		for (int i = 1; i < num.size(); i++) {
			if (num[i]!='['&&num[i] != ','&&num[i] != ']') {
				temp = temp * 10 + num[i] - '0';
			}
			else if(num.size()>2){
				dq.push_back(temp);
				temp = 0;
			}
		}

		int R = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'D') {
				if (dq.empty()) {
					printf("error\n");
					error++;
					break;
				}
				if (R % 2 == 1)dq.pop_front();
				else dq.pop_back();
			}
			else R++;
		}
		if (error == 0 && dq.empty())printf("[]\n");

		if (!dq.empty()) {
			if (R % 2 == 1) {
				printf("[");
				while (!dq.empty()) {
					printf("%d", dq.front());
					dq.pop_front();
					if (!dq.empty())printf(",");
				}
				printf("]\n");
			}
			else {
				printf("[");
				while (!dq.empty()) {
					printf("%d", dq.back());
					dq.pop_back();
					if (!dq.empty())printf(",");
				}
				printf("]\n");
			}
		}

	}
	return 0;
}
#include<iostream>
#include<deque>

using namespace std;

deque<int> dq;

int main() {
	int i, s, k, cnt = 1;
	char c1, c2;
	scanf("%d", &s);
	getchar();
	while (s--) {
		scanf("%c %c", &c1, &c2);
		getchar();
		if (c1 == 'A') {
			if (c2 == 'L') dq.push_front(cnt++);
			else dq.push_back(cnt++);
		}
		else {
			scanf("%d", &k);
			getchar();
			if (c2 == 'L') {
				while (k--) {
					dq.pop_front();
				}
			}
			else {
				while (k--) {
					dq.pop_back();
				}
			}
		}
	}
	while (!dq.empty()) {
		printf("%d\n", dq.front());
		dq.pop_front();
	}
	return 0;
}
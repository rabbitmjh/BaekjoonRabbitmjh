#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <functional>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int n, num;
priority_queue<int, vector<int>, greater<int>>q;
priority_queue<int>q1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		
		if (num < 0)
			q1.push(num);
		else if (num>0)
			q.push(num);
		else{
			if (q.empty()&&q1.empty())
				printf("0\n");
			else if (q1.empty()) {
				printf("%d\n", q.top());
				q.pop();
			}
			else if (q.empty()) {
				printf("%d\n", q1.top());
				q1.pop();
			}
			else {
				if (abs(q.top()) == abs(q1.top())) {
					if (q.top() < q1.top()) {
						printf("%d\n", q.top());
						q.pop();
					}
					else {
						printf("%d\n", q1.top());
						q1.pop();
					}
				}
				else if (abs(q.top()) < abs(q1.top())) {
					printf("%d\n", q.top());
					q.pop();
				}
				else {
					printf("%d\n", q1.top());
					q1.pop();
				}
			}
		}
	}
	return 0;
}
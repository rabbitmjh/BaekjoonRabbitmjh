#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <functional>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int n, num,sum,a;
priority_queue<int, vector<int>, greater<int>>q;
priority_queue<int>q1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		q.push(num);
	}

	while(!q.empty()) {
		if (q.size() == 1) {
			break;
		}
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		sum += (a + b);
		q.push(a + b);
	}
	printf("%d", sum);
	return 0;
}
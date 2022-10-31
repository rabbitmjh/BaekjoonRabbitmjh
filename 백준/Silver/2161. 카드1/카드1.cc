#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

deque <int> dq;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", dq.front());	
		if (i == n - 1)return 0;
		dq.pop_front();
		int m = dq.front();
		dq.pop_front();
		dq.push_back(m);
	}





	return 0;
}
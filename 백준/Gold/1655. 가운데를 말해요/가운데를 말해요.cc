#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
priority_queue<int, vector<int>, greater<int>>q1;
priority_queue<int>q;
int n, a;

int main(){
	cin >> n >> a;
	q.push(a);
	printf("%d\n", a);

	for (int i = 2; i <= n; i++) {
		scanf("%d", &a);
		
		if (q.size() == q1.size()) {
			if (q1.top() < a) {
				int b = q1.top();
				q1.pop();
				q1.push(a);
				q.push(b);
			}
			else q.push(a);
		}
		else if (q.size() > q1.size()) {
			if (q.top() > a) {
				int b = q.top();
				q.pop();
				q.push(a);
				q1.push(b);
			}
			else q1.push(a);
		}
		printf("%d\n", q.top());
	}


	return 0;
}
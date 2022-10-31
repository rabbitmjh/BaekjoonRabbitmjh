#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,a,num,f,sum;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		sum = 0;
		queue <pair<int, int>> q;
		priority_queue <int> q1;
		cin >> num >> f;
		for (int j = 0; j < num; j++) {
			cin >> a;
			q.push({ a,j });
			q1.push(a);
		};
		while (q.size()) {
			int n1 = q.front().first;
			int n2 = q.front().second;
			q.pop();
			if (q1.top() == n1) {
				sum++;
				q1.pop();
				if (n2 == f)break;
			}
			else q.push({ n1,n2 });
		}
		printf("%d\n", sum);
	}
	return 0;
}
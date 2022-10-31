#include<iostream>
#include<deque>
#include<string>
using namespace std;
int n, num;
string a;
int main() {
	deque <int> q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push_back") {
			scanf("%d", &num);
			q.push_back(num);
		}
		else if (a == "push_front") {
			scanf("%d", &num);
			q.push_front(num);
		}
		else if (a == "pop_front") {
			if (q.size() == 0) printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop_front();
			}
		}
		else if (a == "pop_back") {
			if (q.size() == 0) printf("-1\n");
			else {
				printf("%d\n", q.back());
				q.pop_back();
			}
		}
		else if (a == "size") printf("%d\n", q.size());
		else if (a == "empty") printf("%d\n", q.empty());
		else if (a == "front") {
			if (q.size() == 0) printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else if (a == "back") {
			if (q.size() == 0) printf("-1\n");
			else
				printf("%d\n", q.back());
		}
	}
	return 0;
}
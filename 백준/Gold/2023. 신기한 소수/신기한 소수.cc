#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits.h>
#include <math.h>
using namespace std;
typedef pair<int, int> p;
queue <int> q;
vector <int> v;
string arr[4] = { "1","3","7","9" };
int n;

int check(int n) {
	for (int i = 2; i <sqrt(n); i++)
		if (n%i==0)return 0;
	return 1;
}

void go(int x) {
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		string s = to_string(x);
		for (int i = 0; i < 4; i++) {
			s.append(arr[i]);
			int a = stoi(s);
			if (check(a)) {
				if (s.size() == n)v.push_back(a);
				else if (s.size() < n)q.push(a);
			}
			s.pop_back();
		}
	}

}

int main() {
	cin >> n;
	if (n == 1)printf("2\n3\n5\n7\n");
	go(2);
	go(3);
	go(5);
	go(7);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
	return 0;
}

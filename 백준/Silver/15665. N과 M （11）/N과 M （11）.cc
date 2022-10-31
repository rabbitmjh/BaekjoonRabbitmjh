#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, m;
vector <int> v;
vector <int> arr;
int visit[9];
set <vector<int>> s;
void go(int x, int c) {
	//c는 수열 길이 체크 x는 순서 넣기
	if (c == m) {
		s.insert(v);
		return;
	}
	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
		go(i, c + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int b;
		scanf("%d", &b);
		arr.push_back(b);
	}
	sort(arr.begin(), arr.end());
	go(0, 0);
	for (auto i : s) {
		for (auto j : i)printf("%d ", j);
		printf("\n");
	}
	return 0;
}
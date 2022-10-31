#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <string.h>
#include <limits.h>
#include <math.h>
using namespace std;
int n, m;
vector <int> v;
vector <int> arr;
int visit[9];

void go(int x, int c) {
	//c는 수열 길이 체크 x는 순서 넣기
	if (c == m) {
		for (int i = 0; i < v.size(); i++)printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = x; i < n; i++) {
		bool check = true;
		if (!v.empty()) {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == arr[i]) {
					check = false;
					break;
				}
			}
		}
		if (!check)continue;
		v.push_back(arr[i]);
		go(i+1 , c + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	go(0, 0);
	
	return 0;
}
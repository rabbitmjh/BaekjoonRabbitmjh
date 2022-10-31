#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <functional>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int arr[100005],cnt=1,n;
priority_queue<int,vector<int>, greater<int>>q;
priority_queue<int> q1;

void push(int num) {
	arr[cnt] = num;
	int i = cnt;
	cnt++;
	while (i != 1) {
		if (arr[i] > arr[i / 2]) {
			swap(arr[i], arr[i / 2]);
			i /= 2;
		}
		else return;
	}
	return;
}

void pop() {
	if (cnt == 0)return;
	arr[1] = arr[cnt];
	arr[cnt--] = 0;
	int i = 1;
	while (i <= cnt) {
		int next = i;
		if (i * 2 <= cnt && arr[i * 2] < arr[next])next = i * 2;
		if (i * 2 + 1 <= cnt && arr[i * 2 + 1] < arr[next])next = i * 2 + 1;
		if (i == next)return;
		swap(arr[i], arr[next]);
		i = next;
	}
	return;
}
int main() {
	cin >> n;
	arr[n] = 1;
 	for (int i = 1; i < n; i++) {
		push(i+1);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

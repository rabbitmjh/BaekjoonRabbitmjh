#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <deque>
#include <string>
#include <climits>
#include <cmath>
#include <string>
#include <array>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;
//컴퓨터정보공학부 201821240 민지홍 과제#12 palindrome
//그냥 펠린드롬이면 0
//단어를 없애서 펠린드롬을 만들 수 있으면 최대 3까지(1,2,3) 출력
//앞에서 안 걸러지면 -1

int ans = 4, l, r;
string w;

bool palindrome(string str) {
	bool find = true;
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			find = false;
			break;
		}
	}
	return find;
}
void extract(int l, int r, int cnt) {
	if (cnt == 4)return;
	if (l < r) {
		if (w[l] == w[r])
			extract(l + 1, r - 1, cnt);
		else {
			extract(l, r - 1, cnt + 1);
			extract(l + 1, r, cnt + 1);
		}
	}
	else {
		ans = min(cnt, ans);
		return;
	}
}

int main() {
	FIO;
	cin >> w;

	bool check = palindrome(w);
	if (check) {//0인지 카운트
		cout << 0 << endl;
		return 0;
	}
	r = w.size() - 1;

	extract(0, r, 0);
		
	if (ans < 4)cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;


int n, arr[21][21], check[21][21];
int nx[4] = { 0,-1,1,0 }, ny[4] = { -1,0,0,1 };
struct student {
	int x, y;
	int l1, l2, l3, l4;
};
student st[500];
vector <p> v;//1번 좌표확인

int go(int like) {//좋아하는 학생의 인접하는 자리 정리
	p find[4];
	int cnt = 0;
	if (st[st[like].l1].x != 0) {//좋아하는 학생의 자리가 있는지
		for (int i = 0; i < 4; i++) {
			int dx = st[st[like].l1].x + nx[i];
			int dy = st[st[like].l1].y + ny[i];
			if (dx > 0 && dx <= n && dy > 0 && dy <= n)
				check[dx][dy]++;
		}
		cnt++;
	}
	if (st[st[like].l2].x != 0) {//좋아하는 학생의 자리가 있는지
		for (int i = 0; i < 4; i++) {
			int dx = st[st[like].l2].x + nx[i];
			int dy = st[st[like].l2].y + ny[i];
			if (dx > 0 && dx <= n && dy > 0 && dy <= n)
				check[dx][dy]++;
		}
		cnt++;
	}
	if (st[st[like].l3].x != 0) {//좋아하는 학생의 자리가 있는지
		for (int i = 0; i < 4; i++) {
			int dx = st[st[like].l3].x + nx[i];
			int dy = st[st[like].l3].y + ny[i];
			if (dx > 0 && dx <= n && dy > 0 && dy <= n)
				check[dx][dy]++;
		}
		cnt++;
	}
	if (st[st[like].l4].x != 0) {//좋아하는 학생의 자리가 있는지
		for (int i = 0; i < 4; i++) {
			int dx = st[st[like].l4].x + nx[i];
			int dy = st[st[like].l4].y + ny[i];
			if (dx > 0 && dx <= n && dy > 0 && dy <= n)
				check[dx][dy]++;
		}
		cnt++;
	}
	return cnt;
}
int find(int x, int y) {//해당 좌표의 인접한 칸이 얼마나 비어있는지
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int dx = x + nx[i];
		int dy = y + ny[i];
		if (dx > 0 && dx <= n && dy > 0 && dy <= n && arr[dx][dy] == 0) {
			cnt++;
		}
	}
	return cnt;
}
int sat(int nn) {//만족도 조사
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int dx = st[nn].x + nx[i];
		int dy = st[nn].y + ny[i];
		if (dx > 0 && dx <= n && dy > 0 && dy <= n) {
			if (arr[dx][dy] == st[nn].l1 || arr[dx][dy] == st[nn].l2 || arr[dx][dy] == st[nn].l3 || arr[dx][dy] == st[nn].l4)
				cnt++;
		}
	}
	if (cnt == 0)return 0;
	else if (cnt == 1)return 1;
	else if (cnt == 2)return 10;
	else if (cnt == 3)return 100;
	else if (cnt == 4)return 1000;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	int num;
	for (int i = 1; i <= n * n; i++) {
		cin >> num;
		cin >> st[num].l1 >> st[num].l2 >> st[num].l3 >> st[num].l4;

		int likenum = go(num);
		if (num == 23) {
			int asdf = 1;
		}
		if (likenum == 0) {//처음
			int x = -1, y = -1, ma = 0;
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					int a = find(j, k);
					if (a > ma && arr[j][k] == 0) {
						ma = a;
						x = j;
						y = k;
					}
				}
			}
			if (x == -1 && y == -1) {
				bool c = false;
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= n; k++) {
						if (arr[j][k] == 0) {
							x = j;
							y = k;
							c = true;
							break;
						}
					}
					if (c)break;
				}
			}
			st[num].x = x;
			st[num].y = y;
			arr[x][y] = num;
		}
		else {
			int x = -1, y = -1, ma = 0, em = 0;
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (check[j][k] > ma && arr[j][k] == 0) {
						ma = check[j][k];
						x = j;
						y = k;
						em = find(j, k);
					}
					else if (check[j][k] == ma && arr[j][k] == 0 && ma > 0) {
						int a = find(j, k);
						if (em < a) {
							ma = check[j][k];
							x = j;
							y = k;
							em = a;
						}
						else if (em == a) {
							if (j < x) {
								ma = check[j][k];
								x = j;
								y = k;
								em = a;
							}
							else if (j == x && k < y) {
								ma = check[j][k];
								x = j;
								y = k;
								em = a;
							}
						}
					}
				}
			}
			if (x == -1 && y == -1) {//좋아하는 학생이 인접한 칸이 없을 때
				for (int j = 1; j <= n; j++)
					for (int k = 1; k <= n; k++) {
						int a = find(j, k);
						if (arr[j][k] == 0 && a > em) {
							x = j;
							y = k;
							em = a;
						}
						else if (arr[j][k] == 0 && a == em) {
							if (x == -1 && y == -1) {
								x = j;
								y = k;
								em = a;
							}
							if (j < x) {
								x = j;
								y = k;
								em = a;
							}
							else if (j == x && k < y) {
								x = j;
								y = k;
								em = a;
							}
						}
					}
			}
			st[num].x = x;
			st[num].y = y;
			arr[x][y] = num;
		}
		memset(check, 0, sizeof(check));
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += sat(arr[i][j]);
		}
	}
	cout << ans;
	return 0;
}
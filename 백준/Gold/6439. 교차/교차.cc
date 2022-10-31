#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long  long ll;
typedef pair<int, int> p;
struct l {
	int x;
	int y;
};

int arr[1005];
int arr1[1005];
int sum[1005];
vector <int> v;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0)return 1;
	else if (temp < 0)return -1;
	else return 0;
}

bool inter(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	p a = { x1,y1 };
	p b = { x2,y2 };
	p c = { x3,y3 };
	p d = { x4,y4 };
	int ab = ccw(a.first, a.second, b.first, b.second, c.first, c.second) *
		ccw(a.first, a.second, b.first, b.second, d.first, d.second);

	int cd = ccw(c.first, c.second, d.first, d.second, a.first, a.second) *
		ccw(c.first, c.second, d.first, d.second, b.first, b.second);

	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c < b && a < d;
	}
	return ab < 0 && cd < 0;
}


int main() {
	int t; cin >> t;
	while (t--) {
		int ax, ay, bx, by, cx, cy, dx, dy;
		scanf("%d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
		int rx = min(cx, dx), ry = min(cy, dy);
		int rxx = max(cx, dx), ryy = max(cy, dy);
		p s1 = { ax,ay };
		p s2 = { bx,by };
		p a = { rx,ry };
		p b = { rx,ryy };
		p c = { rxx,ryy };
		p d = { rxx,ry };
		if (s1 > s2)swap(s1, s2);
		//c랑 d는 직사각형 = rx ry rxx ryy
		//a랑 b는 선분 = sx sy sxx syy

		bool chk1 = inter(rx, ry, rx, ryy, s1.first, s1.second, s2.first, s2.second);
		bool chk2 = inter(rx, ryy, rxx, ryy, s1.first, s1.second, s2.first, s2.second);
		bool chk3 = inter(rxx, ryy, rxx, ry, s1.first, s1.second, s2.first, s2.second);
		bool chk4 = inter(rxx, ry, rx, ry, s1.first, s1.second, s2.first, s2.second);
		bool chk = false;
		if (min(ax, bx) >= rx && max(ax, bx) <= rxx && min(ay, by) >= ry && max(ay, by) <= ryy)chk = true;

		if (chk1 || chk2 || chk3 || chk4 || chk)printf("T\n");
		else printf("F\n");

	}
	return 0;
}
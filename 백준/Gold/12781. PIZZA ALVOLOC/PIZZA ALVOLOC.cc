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
	int ab = ccw(a.first,a.second, b.first,b.second, c.first,c.second)*
		ccw(a.first,a.second, b.first,b.second, d.first,d.second);

	int cd = ccw(c.first, c.second, d.first, d.second, a.first, a.second)*
		ccw(c.first, c.second, d.first, d.second, b.first, b.second);

	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c < b&&a < d;
	}
	return ab < 0 && cd < 0;
}

int main() {
	int ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	if (inter(ax, ay, bx, by, cx, cy, dx, dy))printf("1");
	else printf("0");


	return 0;
}
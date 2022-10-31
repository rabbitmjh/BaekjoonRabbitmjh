#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;

int n, idx, ret, start, temp1, temp2;

struct Point {
	int s, e;
	Point(int s, int e) : s(s), e(e) {}
	Point() {
		s = 100001;
		e = 100001;
	}
	bool operator < (const Point & a)const {
		return s < a.s;
	}
};
struct Point2 {
	int s, e;
	Point2(int s, int e) : s(s), e(e) {}
	Point2() {
		s = 100001;
		e = 100001;
	}
	bool operator < (const Point2 & a)const {
		return e < a.e;
	}
};
int main() {
	vector<Point> a;
	vector<Point2> a2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &temp1, &temp2);
		a.push_back(Point(temp1, temp2));
		a2.push_back(Point2(temp1, temp2));
	}
	sort(a.begin(), a.end());
	sort(a2.begin(), a2.end());
	int ret = a[n - 1].s - a2[0].e;
	printf("%d\n", ret < 0 ? 0 : ret);
	return 0;
}
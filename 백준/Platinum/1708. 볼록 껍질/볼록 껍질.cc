#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
typedef long  long ll;
typedef pair<int, int> p;
typedef pair<p, int> pp;
typedef pair<p, p> ppp;


struct pnt {
	int x, y;
	int p, q;

	//초기값
	pnt() :pnt(0, 0, 1, 0) {}
	//2개
	pnt(int x1, int y1) :pnt(x1, y1, 1, 0) {}
	//4개
	pnt(int x1, int y1, int p1, int q1) : x(x1), y(y1), p(p1), q(q1) {}
};

bool cmp(pnt& a, pnt& b) {
	//상대좌표 p,q가 1,0이라면 이조건에 걸리지 않고 극점을 위한 정렬조건으로 넘어감
	if (1LL * a.q * b.p != 1LL * a.p * b.q) 
		return 1LL * a.q * b.p < 1LL * a.p * b.q;
	//y값 오름차순 같다면 x값 오름차순
	if (a.y != b.y) 
		return a.y < b.y;
	return a.x < b.x;
}

long long ccw(pnt& a, pnt& b, pnt& c) {
	return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

pnt arr[100005];
stack <int> st;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		arr[i] = pnt(a, b);
	}
	sort(arr, arr + n, cmp);
	//극점 탐색을 위한 정렬

	for (int i = 1; i < n; i++) {
		arr[i].p = arr[i].x - arr[0].x;
		arr[i].q = arr[i].y - arr[0].y;
	}
	sort(arr + 1, arr + n, cmp);
	//극점을 기준으로 정렬

	st.push(0);
	st.push(1);
	//0번~1번 스택 삽입
	
	//0,1은 스택에 있ㅇ으니 2부터 ccw돌림
	int next = 2;
	while (next < n) {
		while (st.size() >= 2) {
			int first = st.top();
			st.pop();
			int second = st.top();
			
			//내각이 180도 미만인지
			if (ccw(arr[second], arr[first], arr[next]) > 0) {
				st.push(first);
				break;
			}
		}
		st.push(next++);
	}
	printf("%d", st.size());

	return 0;
}
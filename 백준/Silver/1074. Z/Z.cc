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
//백준 1074 Z

ll n, r, c, ans;

void snake(ll nx, ll ny, ll stx, ll enx, ll sty, ll eny, ll n) {
	
	if(n == 0) return;
	if(r < ny&&nx <= c) {//1사분면
		ans += pow(pow(2, n), 2) / 4;
		snake((nx + enx) / 2, (sty + ny) / 2, 
			  (stx + enx) / 2, enx, sty, (sty + eny) / 2, n - 1);
		return;
	}
	else if(r < ny&&c < nx) {//2사분면
		snake((stx + nx) / 2, (sty + ny) / 2,
			  stx, (stx + enx) / 2, sty, (sty + eny) / 2, n - 1);
		return;
	}
	else if(ny <= r&&c < nx) {//3사분면
		ans += pow(pow(2, n), 2) / 4 * 2;
		snake((stx + nx) / 2, (ny + eny) / 2,
			  stx, (stx + enx) / 2, (sty + eny) / 2, eny, n - 1);
		return;
	}
	else if(ny <= r&&nx <= c) {//4사분면
		ans += pow(pow(2, n), 2) / 4 * 3;
		snake((nx + enx) / 2, (ny + eny) / 2,
			  (stx + enx) / 2, enx, (sty + eny) / 2, eny, n - 1);
		return;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> c;
	
	ll nx = pow(2, n) / 2;
	
	snake(nx, nx, 0, pow(2, n), 0, pow(2, n), n);
	
	cout << ans << endl;	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <limits>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
typedef pair <int, p> pp;
//백준18111 마인크래프트

int arr[260];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//블록 캐기 2초 블록 놓기 1초
	ll n, m, b, time = 2147483647, floor;
	cin >> n >> m >> b;
	
	int mn = 256 , mx = 0;
	for (int i = 0; i < n * m; i++) {
		int a; cin >> a;
		arr[a]++;
		mn = min(mn, a);
		mx = max(mx, a);
	}
	
	for (int i = mn; i <= mx; i++) {
		ll sum = 0, p = 0, q = 0 , inven = b;
		//p는 i층보다 높은 블록 개수
		//q는 i층보다 낮은 블록 개수
		//sum은 i층에서 걸리는 시간
		for (int j = mn; j < i; j++)
			q += arr[j] * (i - j);
		for (int j = i + 1; j <= mx; j++)
			p += arr[j] * (j - i);
		
		inven += p;
		sum += p * 2;
		if (inven >= q) sum += q;
		else continue;
		if (time >= sum) {
			floor = i;
			time = sum;
		}
	}
	cout << time << " " << floor << "\n";
	
	
    return 0;
}

#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> p;
typedef pair <int, p> pp;

vector <ll> v;
//백준2805 나무 자르기

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n , m;
	cin >> n >> m;
	v.resize(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end(), greater<>());
	ll mn = 0, mx = v.front(), ans = 0;
	while(mn <= mx){
		ll sum = 0,  mid = (mx + mn) / 2;;
		for(int i = 0; i < v.size(); i++){
			if(mid >= v[i])break;
			sum += v[i] - mid;
		}
		if(sum >= m){
			ans = max (ans, mid);
			mn = mid + 1;
		}
		else
			mx = mid - 1;
	}
	cout << ans;
    return 0;
}
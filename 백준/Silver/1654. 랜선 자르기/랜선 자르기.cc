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
typedef pair<int, int>p;
typedef pair<int, p> pp;

vector <ll> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll k,n;cin>>k>>n;
	for(int i=0;i<k;i++){
		int a;cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	
	
	ll mn=1,mx=v.back();
	while(mn<=mx){
		ll mid=(mx+mn)/2;
		ll sum=0;
		for(int i=0;i<v.size();i++)
			sum+=v[i]/mid;
		
		if(sum>=n)
			mn=mid+1;
		
		else
			mx=mid-1;
		
	}
	cout<<mx;
    return 0;
}
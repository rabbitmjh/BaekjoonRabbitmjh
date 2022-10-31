#include <iostream>
#include <algorithm>
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


int main(){
	int t;cin>>t;
	while(t--){
		int h,w,n;
		cin>>h>>w>>n;
		int ans=n/h+1;
		int sum=n%h;
		if(!sum){
			sum=h;
			ans--;
		}
		if(ans<10)cout<<sum<<'0'<<ans<<endl;
		else cout<<sum<<ans<<endl;
	}
    return 0;
}

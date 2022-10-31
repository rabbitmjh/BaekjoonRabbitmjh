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
int coin[15];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		scanf("%d",&coin[i]);
	int ans=0;
	
	for(int i=n-1;i>-1;i--){
		if(coin[i]<=k){
			ans+= k/coin[i];
			k%=coin[i];
		}
	}
	cout<<ans<<endl;
    return 0;
}

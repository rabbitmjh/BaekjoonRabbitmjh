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

int arr[2005];
int ans[2005][2005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	
	for(int i=1;i<=n;i++) ans[i][i]=1;
	for(int i=1;i<n;i++)if(arr[i]==arr[i+1])ans[i][i+1]=1;
	for(int i=2;i<n;i++)
		for(int j=1;j<=n-i;j++){
			if((arr[j]==arr[j+i])&&ans[j+1][i+j-1])
				ans[j][j+i]=1;
		}
	
	
	int m;cin>>m;
	while(m--){
		int a,b;cin>>a>>b;
		cout<<ans[a][b]<<"\n";
	}
	
    return 0;
}
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

int arr[15][15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,};

int main(){
	int t;cin>>t;
	for(int i=1;i<=14;i++){
		for(int j=1;j<=14;j++){
			if(j==1)arr[i][j]=1;
			else{
				arr[i][j]=arr[i][j-1]+arr[i-1][j];
			}
		}
	}
	while(t--){
		int n,k;cin>>k>>n;
		cout<<arr[k][n]<<endl;
	}
    return 0;
}

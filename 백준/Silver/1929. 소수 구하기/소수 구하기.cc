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

int arr[1000005];
int main(){
	int n,m; cin>>n>>m;
	int num=2;
	for(int i=2;i<1000005;i++){
		if(arr[i])continue;
		for(int j=i*2;j<1000005;j+=i){
			arr[j]=1;
		}
	}
	for(int i=n;i<=m;i++){
		if(i==1)continue;
		if(!arr[i])printf("%d\n",i);
	}
    return 0;
}

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
int arr[1025][1025];


int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int a;scanf("%d",&a);
			arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+a;
		}
	
	while(m--){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n",arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]);
	}
	
    return 0;
}

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
int arr[1005][3], ans[1005][3];
int sum;

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
	
	//0 = 빨강/ 1 = 초록/ 2 = 파랑
	
	ans[0][0]=arr[0][0];
	ans[0][1]=arr[0][1];
	ans[0][2]=arr[0][2];
	for(int i=1;i<n;i++){
		int a=arr[i][0];
		int b=arr[i][1];
		int c=arr[i][2];
		
		ans[i][0]=a+min(ans[i-1][1],ans[i-1][2]);
		ans[i][1]=b+min(ans[i-1][0],ans[i-1][2]);
		ans[i][2]=c+min(ans[i-1][0],ans[i-1][1]);
	}
	printf("%d",min(ans[n-1][0],min(ans[n-1][1],ans[n-1][2])));
	
    return 0;
}

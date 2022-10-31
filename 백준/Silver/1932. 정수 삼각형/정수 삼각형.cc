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
int arr[500][500], ans[500][500];
int sum;

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			scanf("%d",&arr[i][j]);
	ans[0][0]=arr[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			sum=max(sum,ans[i][j]);
			if(ans[i+1][j]<ans[i][j]+arr[i+1][j])
				ans[i+1][j]=ans[i][j]+arr[i+1][j];
			if(ans[i+1][j+1]<ans[i][j]+arr[i+1][j+1])
				ans[i+1][j+1]=ans[i][j]+arr[i+1][j+1];
		}
	}
	printf("%d",sum);
    return 0;
}

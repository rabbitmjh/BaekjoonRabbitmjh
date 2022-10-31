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
int x[1005],y[1005];
int main(){
	int x1,y1,x2,y2,x3,y3;
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	x[x1]++;x[x2]++;x[x3]++;
	y[y1]++;y[y2]++;y[y3]++;
	
	int ans1,ans2;
	if(x[x1]==1)ans1=x1;
	else if(x[x2]==1)ans1=x2;
	else ans1=x3;
	
	if(y[y1]==1)ans2=y1;
	else if(y[y2]==1)ans2=y2;
	else ans2=y3;
	
	printf("%d %d",ans1,ans2);
    return 0;
}

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
typedef pair<int,int> p;

int main(){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	
	if(a1<=x1&&b1<=y1&&a2<=x2&&b2>=y2)printf("%d",abs(x2-a2)*abs(y1-y2));//왼쪽커버
	else if(a1>=x1&&b1<=y1&&a2>=x2&&b2>=y2)printf("%d",abs(x1-a1)*abs(y1-y2));//오른쪽커버
	else if(a1<=x1&&b1<=y1&&a2>=x2&&b2<=y2)printf("%d",abs(x2-x1)*abs(y2-b2));//아래커버
	else if(a1<=x1&&b1>=y1&&a2>=x2&&b2>=y2)printf("%d",abs(x2-x1)*abs(y1-b1));//위커버
	else printf("%d",abs(x2-x1)*abs(y2-y1));
	return 0;
}
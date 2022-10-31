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

int main(){
	int t;cin>>t;
	while(t--){
		double x1,y1,r1,x2,y2,r2;
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
		double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		double sum=r1+r2,mx=max(r1,r2),mn=min(r1,r2);
		
		if(dis<=mx){//내접
			if(x1==x2&&y1==y2){//같은 점인 경우
				if(r1==r2)printf("-1\n");//거리까지 같으면 무한대
				else printf("0\n");
			}
			else if(dis+mn>mx)printf("2\n");
			else if(dis+mn==mx)printf("1\n");
			else printf("0\n");
		}
		else{//외접
			if(x1==x2&&y1==y2){//같은 점인 경우
				if(r1==r2)printf("-1\n");//거리까지 같으면 무한대
				else printf("0\n");
			}
			else if(dis<sum)printf("2\n");
			else if(dis==sum)printf("1\n");
			else printf("0\n");
		}
	}
    return 0;
}

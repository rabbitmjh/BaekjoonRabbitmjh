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


int main(){
	int n,cnt=1,sum=0;
	cin>>n;
	while(1){
		sum+=cnt;
		if(sum>=n){
			sum-=cnt;
			break;
		}
		cnt++;
	}

	if(cnt%2){
		int a=cnt,b=1;
		for(int i=sum+1;i<n;i++){
			a--;b++;
		}
		printf("%d/%d",a,b);
	}
	else{
		int a=1,b=cnt;
		for(int i=sum+1;i<n;i++){
			a++;b--;
		}
		printf("%d/%d",a,b);
	}
   
    return 0;
}

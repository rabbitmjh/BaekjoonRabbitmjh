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

int arr[300005];
int main(){
	int num=2;
	for(int i=2;i<300005;i++){
		if(arr[i])continue;
		for(int j=i*2;j<300005;j+=i){
			arr[j]=1;
		}
	}
	arr[1]=1;
	while(1){
		int a;scanf("%d",&a);
		if(!a)break;
		int sum=0;
		for(int i=a+1;i<=2*a;i++){
			if(!arr[i])sum++;
		}
		printf("%d\n",sum);
		
	}
    return 0;
}

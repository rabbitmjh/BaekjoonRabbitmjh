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

int arr[10005];
int main(){
	int num=2;
	for(int i=2;i<10005;i++){
		if(arr[i])continue;
		for(int j=i*2;j<10005;j+=i){
			arr[j]=1;
		}
	}
	arr[1]=1;
	int a; scanf("%d",&a);
	while(a){
		int n;scanf("%d",&n);
		int x,y; x=y=n/2;
		while(1){
			if(!arr[x]&&!arr[y]){
				printf("%d %d\n",x,y);
				break;
			}
			x--;
			y++;
		}
		a--;
	}
    return 0;
}

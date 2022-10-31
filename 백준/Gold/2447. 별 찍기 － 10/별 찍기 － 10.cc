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
int arr[6600][6600];
void star(int i,int j,int n){
	if(i%3==1&&j%3==1){
		printf(" ");
		return;
	}
	else if(n%3==1){
		printf("*");
		return;
	}
	else star(i/3,j/3,n/3);
}


int main(){
	int n,cnt=0; cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			star(i,j,n);
		}
		printf("\n");
	}
	
    return 0;
}

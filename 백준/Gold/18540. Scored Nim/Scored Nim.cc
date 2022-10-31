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
int arr[130];

int main(){
	int n,sum=0;
	cin>>n;
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	
	
	cout<<(sum+1)/2<<endl;
    return 0;
}

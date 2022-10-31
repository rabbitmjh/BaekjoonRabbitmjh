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
p arr[100005];

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d %d",&arr[i].first,&arr[i].second);
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++){
		printf("%d %d\n",arr[i].first,arr[i].second);
	}
    return 0;
}

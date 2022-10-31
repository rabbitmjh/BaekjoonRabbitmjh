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
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		arr[a]++;
	}
	for(int i=1;i<=10000;i++)
		for(int j=0;j<arr[i];j++)
			printf("%d\n",i);

	
    return 0;
}

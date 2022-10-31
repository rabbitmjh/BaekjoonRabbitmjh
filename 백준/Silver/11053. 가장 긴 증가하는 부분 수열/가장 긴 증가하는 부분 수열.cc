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
ll arr[1005];
vector<p> v;
int main(){
	int n,cnt=1;
	cin>>n;
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		int m=0;
		for(int j=0;j<v.size();j++){
			if(v[j].first<a){
				m=max(v[j].second,m);
			}
		}
		m++;
		v.push_back({a,m});
	}
	
	int sum=0;
	for(int i=0;i<v.size();i++)
		sum=max(v[i].second,sum);
	printf("%d",sum);
	
    return 0;
}

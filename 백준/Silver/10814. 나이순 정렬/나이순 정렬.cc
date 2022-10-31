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
struct people{
	int age;
	char name[105];
};
char arr[100005][101];
vector<p>v;

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a;scanf("%d",&a);
		scanf("%s",arr[i]);
		v.push_back({a,i});
	}
	sort(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++){
		printf("%d ",v[i].first);
		printf("%s\n",arr[v[i].second]);
	}
	
    return 0;
}
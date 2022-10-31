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
vector<int>v;
int main(){
	while(1){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		if(!a)break;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(),v.end());
		
		if(v[2]*v[2]==(v[1]*v[1]+v[0]*v[0]))printf("right\n");
		else printf("wrong\n");
		v.clear();
	}
    return 0;
}

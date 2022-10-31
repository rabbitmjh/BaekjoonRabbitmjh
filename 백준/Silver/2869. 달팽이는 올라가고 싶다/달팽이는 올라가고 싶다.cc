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
	int a,b,v;
	cin>>a>>b>>v;
	v-=a;
	int sum=v%(a-b),ans=v/(a-b);
	if(!sum)cout<<ans+1;
	else cout<<ans+2;
    return 0;
}

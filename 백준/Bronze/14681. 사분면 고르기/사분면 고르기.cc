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

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    if(n>0&&m>0)cout<<1;
    else if(n>0&&m<0)cout<<4;
    else if(n<0&&m>0)cout<<2;
    else cout<<3;
    
    return 0;
}

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
    int a,b,c;
    c=m%10;
    b=(m%100-c)/10;
    a=(m-b*10-c)/100;
    printf("%d\n",n*c);
    printf("%d\n",n*b);
    printf("%d\n",n*a);
    printf("%d",n*m);
    return 0;
}

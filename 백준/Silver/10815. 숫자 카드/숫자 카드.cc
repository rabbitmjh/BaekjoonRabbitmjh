#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int m;
vector<int> v;
int main()
{
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        v[i]= x;
    }
    sort(v.begin(),v.end());
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        int x;
        scanf("%d",&x);
        printf("%d ",binary_search(v.begin(),v.end(),x));
    }
 
}
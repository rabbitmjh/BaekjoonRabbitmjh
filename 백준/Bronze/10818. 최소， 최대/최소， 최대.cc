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
vector <int> v;
int main()
{
    int n,m;
   cin>>n;
   for(int i=0;i<n;i++){
       scanf("%d",&m);
       v.push_back(m);
   }
    sort(v.begin(),v.end());
    cout<<v.front()<<" "<<v.back()<<endl;
    
    return 0;
}

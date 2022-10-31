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
string arr[100005];

int main(){
    int n,a=0,cnt=1,sum=1;
    cin>>n;
    while(1){
        if(sum>=n){
            cout<<cnt;
            break;
        }
        a+=6;
        sum+=a;
        cnt++;
        
    }
    return 0;
}

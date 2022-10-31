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
    int a,b,c,cnt=0;
    cin>>a>>b>>c;
    int sum=a;
    if(b>=c){
        cout<<-1;
        return 0;
    }
    cout<<a/(c-b)+1;
    return 0;
}

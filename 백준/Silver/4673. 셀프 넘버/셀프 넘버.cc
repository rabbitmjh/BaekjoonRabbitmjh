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
int arr[10005];
int main(){
    for(int i=1;i<=10000;i++){
        int sum=i,a=i;
        
        while(a){
            int b=a%10;
            sum+=b;
            a/=10;
        }
        if(sum>10000)continue;
        else arr[sum]=1;
    }
    for(int i=1;i<=10000;i++)
        if(!arr[i])printf("%d\n",i);
    return 0;
}

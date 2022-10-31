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
vector <string> v;

int main(){
    int n,cnt=0;cin>>n;
    while(n--){
        string s;
        cin>>s;
        v.push_back(s);
    }
    for(int i=0;i<v.size();i++){
        bool check=true;
        int arr[26];
        memset(arr,0,sizeof(arr));
        if(v[i].size()==1){
            cnt++;
            continue;
        }
        for(int j=0;j<v[i].size()-1;j++){
            if(arr[v[i][j]-97]||arr[v[i][j+1]-97]){
                check=false;
                break;
            }
            if(v[i][j]!=v[i][j+1]){
                arr[v[i][j]-97]=1;
            }
        }
        if(check)cnt++;
    }
    cout<<cnt;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int n, arr[105];
vector <int> v;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        v.insert(v.end()-arr[i], i);   
        
    }
    for(int i = 0; i <n; i++){
        cout << v[i];
        cout<<" ";
    }
    
    
    return 0;
}
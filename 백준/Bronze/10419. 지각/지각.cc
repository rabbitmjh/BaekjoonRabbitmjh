#include <iostream>
using namespace std;

int t, n;

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int tmp=0;
        for(tmp;;tmp++){
            if(tmp+tmp*tmp>n)
                break;
        }
        
        cout<<tmp-1<<"\n";
    }

    return 0;
}
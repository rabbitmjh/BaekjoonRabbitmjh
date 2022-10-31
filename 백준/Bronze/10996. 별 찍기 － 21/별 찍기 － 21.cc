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
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n;j++){
            if(i%2){
                if(j%2) printf("*");
                else printf(" ");
            }
            else{
                if(j%2) printf(" ");
                else printf("*");
            }
        }
        printf("\n");
    }
    
    return 0;
}

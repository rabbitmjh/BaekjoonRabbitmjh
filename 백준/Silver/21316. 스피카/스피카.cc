#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int arr[13][13];
int check[13];

int main(){
    int a,b,c1,c2,c3;
    
    for(int i=0;i<12;i++){
        scanf("%d %d",&a,&b);
        arr[a][b] = 1;
        arr[b][a] = 1;
        check[a]++;
        check[b]++;
    }
    
    for(int i=1;i<=12;i++){
        if(check[i] == 3){
            c1 = c2 = c3 = 0;
        }
        for(int j = 1;j <= 12;j++){
            if(arr[i][j] == 1){
                if(check[j] == 1) c1++;
                else if(check[j] == 2) c2++;
                else c3++;
                if(c1 == 1 && c2 == 1 && c3 == 1){
                    printf("%d",i);
                    return 0;
                }
            }
        }
    }
    return 0;
}

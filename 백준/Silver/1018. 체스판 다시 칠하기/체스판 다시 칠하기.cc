#include <iostream>
#include <algorithm>
#include <utility>
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
char arr[55][55];
char wh[8][8]={
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};
char bl[8][8]={
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int cnt=64;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if((n-i)>7&&(m-j)>7){
				int whi=0;
				int bla=0;
				for(int a=i;a<i+8;a++){
					for(int b=j;b<j+8;b++){
						if(wh[a-i][b-j]!=arr[a][b])whi++;
						if(bl[a-i][b-j]!=arr[a][b])bla++;
					}
				}
				cnt=min(cnt,min(whi,bla));
			}
		}
	}
	cout<<cnt<<endl;
    return 0;
}
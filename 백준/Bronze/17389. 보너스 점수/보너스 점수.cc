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


int main(){
	int n;cin>>n;
	string s;cin>>s;
	
	int sum=0,bonus=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='X')bonus=0;
		else{
			sum+=i+bonus;
			bonus++;
		}
	}
	cout<<sum;
    return 0;
}

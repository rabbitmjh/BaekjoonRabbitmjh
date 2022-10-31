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
	int s,k,h;
	cin>>s>>k>>h;
	if(s+k+h>=100)cout<<"OK";
	else{
		int m=min(s,min(k,h));
		if(s==m)cout<<"Soongsil";
		else if(k==m)cout<<"Korea";
		else cout<<"Hanyang";
	}
    return 0;
}

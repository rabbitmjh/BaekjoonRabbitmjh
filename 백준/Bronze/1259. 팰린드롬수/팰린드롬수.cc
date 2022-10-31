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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(1){
		string s;
		cin>>s;
		if(s=="0")break;
		bool check=true;
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1])
				check=false;
		}
		if(check==true)printf("yes\n");
		else printf("no\n");
	}
	
    return 0;
}
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

vector <int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;cin>>num;
	int cnt=0;
	int n=1;
	
	while(1){
		string s=to_string(n);
		if(s.find("666")!=-1)++cnt;
		if(cnt==num){
			cout<<n;
			break;
		}
		n++;
		
	}
    return 0;
}
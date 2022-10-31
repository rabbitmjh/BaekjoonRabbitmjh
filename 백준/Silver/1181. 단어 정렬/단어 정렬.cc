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
vector <vector <string>> v(55);

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		v[s.size()].push_back(s);
	}
	for(int i=1;i<=50;i++)
		sort(v[i].begin(),v[i].end());
	
	string check="A";
	for(int i=1;i<=50;i++){
		for(int j=0;j<v[i].size();j++){
			if(check!=v[i][j]){
				cout<<v[i][j]<<endl;
				check=v[i][j];
			}
			else continue;
		}
	}
    return 0;
}

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
queue <int> q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		q.push(i);
	while(!q.empty()){
		if(q.size()==1){
			cout<<q.front()<<endl;
			break;
		}
		q.pop();
		int a=q.front();
		q.pop();
		q.push(a);
	}
    return 0;
}
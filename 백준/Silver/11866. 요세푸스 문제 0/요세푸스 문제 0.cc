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
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)
		q.push(i);
	
	int i=0;
	printf("<");
	while(!q.empty()){
		i++;
		if(q.size()==1){
			printf("%d",q.front());
			q.pop();
		}
		else if(i%k==0){
			printf("%d, ",q.front());
			q.pop();
		}
		else{
			int next=q.front();
			q.pop();
			q.push(next);
		}
	}
	printf(">");
    return 0;
}

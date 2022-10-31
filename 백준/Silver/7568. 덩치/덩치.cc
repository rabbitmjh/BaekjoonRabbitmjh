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

int x[55],y[55];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	
	for(int i=0;i<n;i++){
		int rank=1;
		for(int j=0;j<n;j++){
			if(x[i]<x[j]&&y[i]<y[j])rank++;
		}
		cout<<rank<<" ";
	}
    return 0;
}
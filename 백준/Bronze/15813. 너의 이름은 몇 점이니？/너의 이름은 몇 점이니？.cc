#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string>
using namespace std;


int main(){
	int n,sum=0;
	string s;
	cin>>n>>s;

	for(int i=0;i<s.size();i++) sum+=s[i]-64;
	cout<<sum<<endl;
}
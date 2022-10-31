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

int arr[500005];
vector <int> out;
int cnt[8005];
/*산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//백준 2108
	int n;cin>>n;
	int mn=5000,mx=-5000;
	double sum=0;
	vector <int> v;
	int c=0,a=n-1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mn=min(mn,arr[i]);
		mx=max(mx,arr[i]);
		cnt[arr[i]+4000]++;
		sum+=arr[i];
	}
	

	for(int i=0;i<=8000;i++){//중앙값
		for(int j=0;j<cnt[i];j++)
			out.push_back(i-4000);
	}
	
	
	for(int i=0;i<=8000;i++){
		if(cnt[i]>c){
			v.clear();
			c=cnt[i];
			v.push_back(i-4000);
		}
		else if(cnt[i]==c){
			v.push_back(i-4000);
		}
		else continue;
	}
	
	sort(v.begin(),v.end());
	
	cout << fixed;
	cout.precision(1);
	cout<<int(round(sum/n))<<"\n";//산술평균
	cout<<out[out.size()/2]<<"\n";//중앙값
	if(v.size()>1)cout<<v[1]<<"\n";
	else cout<<v[0]<<"\n";//최빈값
	cout<<mx-mn<<"\n";//범위
    return 0;
}
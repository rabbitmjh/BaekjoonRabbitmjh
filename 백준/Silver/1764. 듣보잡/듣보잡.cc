#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<string.h>
using namespace std;
int n,m,sum;

int main() {
	vector <string> v;
	vector <string> v1;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == v[i + 1]) {
			v1.push_back(v[i]);
			i++;
		}
	}
	printf("%d\n", v1.size());
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}
	return 0;
}
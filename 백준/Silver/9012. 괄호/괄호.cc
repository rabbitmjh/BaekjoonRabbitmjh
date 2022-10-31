#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<cmath>
using namespace std;
int n,a;
string s;
int main() {
	stack <char> st;
	cin >> n;
	for (int i = 0; i < n; i++) {
		a = 0;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(')st.push(s[j]);
			else if(s[j] ==')'&&!st.empty())
				st.pop();
			else {
				printf("NO\n");
				a++;
				break;
			}
		}
		if (a > 0)continue;
		if (!st.empty()) {
			printf("NO\n");
			while(!st.empty())st.pop();
		}
		else printf("YES\n");
	}

	return 0;
}
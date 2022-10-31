#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
string s;
int sum;
int main() {
	stack <char> st;
	vector <int> v;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '('&&s[i + 1] == ')'&&!st.empty()) {
			for (int j = 0; j < st.size(); j++) v[j]++;
			i++;
		}
		else if (s[i] == '('&&s[i + 1] == ')'&&st.empty()) i++;
		else if (s[i] == '('&&s[i + 1] != ')') {
			st.push(s[i]);
			v.push_back(1);
		}
		else if (s[i] == ')'&&s[i - 1] != '(') {
			st.pop();
		}
	}
	for (int i = 0; i < v.size(); i++)sum += v[i];
	printf("%d", sum);
	return 0;
}
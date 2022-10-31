#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int n, a[100001],s;

int main() {
	stack <int> st;
	vector <char> st1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		st.push(i);
		st1.push_back('+');
		while (!st.empty() && st.top() == a[s]) {
			s++;
			st.pop();
			st1.push_back('-');
		}
	}
	if (!st.empty()) {
		printf("NO");
		return 0;
	}
	else 
		for (int i = 0; i < st1.size(); i++)printf("%c\n", st1[i]);
	return 0;
}
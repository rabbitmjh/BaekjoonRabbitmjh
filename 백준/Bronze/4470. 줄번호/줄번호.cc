#include <iostream>
#include <string>
using namespace std;

int n;
char c[55];

int main() {
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 1; i <= n; i++) {
		getline(cin, s);
		
		cout << i << ". " << s << endl;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
//백준 1541 잃어버린 괄호

vector <int> v;
string str;
char s[55];
int ans;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	scanf("%s", s);
	for(int i = 0; i < sizeof(s); i++) {
		if(s[i] == '\000') {
			v.push_back(stoi(str));
			break;
		}
		if(s[i] == '-') {
			v.push_back(stoi(str));
			v.push_back(-1);
			str.clear();
		}
		else if(s[i] == '+') {
			v.push_back(stoi(str));
			v.push_back(-2);
			str.clear();
		}
		else
			str.push_back(s[i]);	
	}
	
	int num = 0;
	for(int i = 0; i < v.size(); i++) {
		int n = 0;
		if(v[i] == -1) {
			while(1) {
				i++;
				if(i >= v.size()) {
					ans -= n;
					break;
				}
				if(v[i] == -2)	continue;
				else if(v[i] == -1) {
					ans -= n;
					i--;
					break;
				}
				else n += v[i];
			}
		}
		else if(v[i] != -2) {
			ans += v[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}

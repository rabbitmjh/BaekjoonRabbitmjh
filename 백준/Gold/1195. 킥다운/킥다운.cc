#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string s1, s2;

int main() {
    FIO;
	
	cin >> s1 >> s2;

	if (s1.size() > s2.size())
		swap(s1, s2);
        
	int ans = s1.size() + s2.size();
	for (int i = 0; i < s1.size(); i++) {
		int s1_len = s1.size();
		bool flag = false;
		for (int j = 0; j <= i; j++) {
			if (s2[j] =='2' && s1[s1_len - 1 - i + j] == '2') {
				flag = true;
				break;
			}
		}
		if (!flag)
			ans = min(ans, (int)s1.size() + (int)s2.size() - 1 - i);
	}
	for (int i = 0; i < s1.size(); i++) {
		int s2_len = s2.size();
		bool flag = false;
		for (int j = 0;j <= i;j++) {
			if (s2[s2_len - 1 - i + j] == '2' &&  s1[j] == '2') {
				flag = true;
				break;
			}
		}
		if (!flag)
			ans = min(ans, (int)s1.size() + (int)s2.size() - 1 - i);
	}

	for (int i = 0; i < s2.size() - s1.size(); i++) {
		bool flag = false;
		for (int j = 0; j < s1.size(); j++) {
			if (s1[j] == '2' && s2[i + j] == '2') {
				flag = true;
				break;
			}
		}
		if (!flag)
			ans = min(ans,(int)s2.size());
	}
	cout << ans;
    
    return 0;
}
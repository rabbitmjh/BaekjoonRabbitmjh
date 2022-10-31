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

string s;
vector <char> v;
vector <char> v1;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s;
	int cnt = 0;//M이 몇 번 들어왔는지 카운트
	//제일 큰 값
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'K'){//K가 들어왔을때 앞에 M의 개수만큼 뒤에 0을 붙여줌
			if (cnt > 0) {
				v.push_back('5');
				while (cnt) {
					v.push_back('0');
					cnt--;
				}
			}
			else//앞에 M이 0개면 그냥 5 넣음
				v.push_back('5');
		}
		else //s[i]가 M이면 카운트+1
			cnt++;

		if (i == s.size() - 1 && cnt > 0) {//마지막일때 M이면 앞에 M의 개수만큼 100...이렇게 넣어줌
			v.push_back('1');
			cnt--;
			while (cnt) {
				v.push_back('1');
				cnt--;
			}
		}
	}

	cnt = 0;
	//제일 작은 값
	//방식은 큰 값과 비슷하지만 하나씩 다 잘라서 넣는데 예외로 M이 여러개 붙을때만 처리
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'K') {
			if (cnt == 0)
				v1.push_back('5');
			else {
				v1.push_back('1');
				cnt--;
				while (cnt > 0) {
					v1.push_back('0');
					cnt--;
				}
				v1.push_back('5');
			}
		}
		else {
			cnt++;
		}
		if (i == s.size() - 1 && cnt > 0) {//마지막에 똑같이 처리
			v1.push_back('1');
			cnt--;
			while (cnt) {
				v1.push_back('0');
				cnt--;
			}
		}
	}

	for (int i = 0;i < v.size();i++)
		cout << v[i];
	cout << endl;
	for (int i = 0;i < v1.size();i++)
		cout << v1[i];
	
	return 0;
}
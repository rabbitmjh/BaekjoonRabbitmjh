#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, string> p;
typedef pair<int, p> pp;

int n, m, k, arr[105][105], aa[105][105], sum[105];
string s[105];
vector <p> v;

int main() {
	FIO;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		cin >> s[i];
	
	while (k--) {
		int num, pa; string time, name, ans;
		cin >> num >> time >> name >> ans;
		for (int i = 0; i < m; i++) {
			if (s[i] == name) {
				pa = i;
				break;
			}
		}
		int t = ((time[0] - '0') * 60 * 10) + ((time[1] - '0') * 60) + ((time[3] - '0') * 10) + (time[4] - '0');

		if (ans == "solve") {
			if (!arr[num][pa])
				aa[num][pa] = -1;//바로 정답 제출시
			else {
				if (aa[num][pa] > 0 || aa[num][pa] == -1)
					continue;//이미 정답제출했으면 넘어감
				aa[num][pa] = t - arr[num][pa];//걸린시간넣음
			}
		}
		else {
			if (!arr[num][pa] && aa[num][pa] != -1)
				arr[num][pa] = t;
			else
				continue;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (aa[i][j] == -1 || !arr[i][j])//바로정답제출or제출기록없음
				sum[j] += m + 1;
			else if (!aa[i][j])
				sum[j] += m;//틀리고해결못함
			else {
				v.push_back({ aa[i][j],s[j] });
			}
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); j++) {
			for (int l = 0; l < m; l++) {
				if (s[l] == v[j].second)
					sum[l] += j + 1;
			}
		}
		v.clear();
	}
	for (int i = 0; i < m; i++)
		v.push_back({ sum[i],s[i] });
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i].second << "\n";

	return 0;
}

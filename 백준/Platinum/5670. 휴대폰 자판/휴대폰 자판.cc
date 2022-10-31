#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
#define alpha 26
#define maxn 100000
bool inital;
int ans, n;
char arr[maxn][81];

struct trie {
	trie* child[alpha];
	bool finish;
	int cnt;

	trie() {
		for (int i = 0; i < alpha; ++i)
			child[i] = nullptr;
		finish = false;
		cnt = 0;
	}
	~trie() {
		for (int i = 0; i < alpha; ++i)
			if (child[i] != nullptr)
				delete child[i];
	}

	void insert(char* str) {
		if (*str == '\0') {
			finish = true;
			return;
		}


		int cur = *str - 'a';
		if (child[cur] == nullptr) {
			child[cur] = new trie();
			cnt++;
		}
		child[cur]->insert(str + 1);
	}

	void find(char* str) {
		if (*str == '\0')
			return;

		if (inital) {
			inital = false;
			ans++;
		}
		else {
			if (finish)
				ans++;
			else if (cnt > 1)
				ans++;
		}

		int cur = *str - 'a';
		child[cur]->find(str + 1);
	}
};

int main() {
	FIO;
	while (cin >> n) {
		trie* root = new trie();
		ans = 0;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			root->insert(arr[i]);
		}

		for (int i = 0; i < n; ++i) {
			inital = true;
			root->find(arr[i]);
		}

		cout << fixed << setprecision(2) << (double)ans / (double)n << '\n';
		delete root;

	}
	return 0;
}

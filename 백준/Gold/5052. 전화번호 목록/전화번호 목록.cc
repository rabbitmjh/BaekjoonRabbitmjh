#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
const int ptr_num = 10;

struct  Trie {
	Trie* child[ptr_num];
	bool finish, haveChild;
	Trie() {
		fill(child, child + ptr_num, nullptr);
		finish = haveChild = false;
	}
	~Trie() {
		for (int i = 0; i < ptr_num; i++)if (child[i])delete child[i];
	}
	void insert(char* key) {
		if (*key == '\0')finish = true;
		else {
			int next = *key - '0';
			if (!child[next])child[next] = new Trie;
			haveChild = true;
			child[next]->insert(key + 1);
		}
	}
	bool chk() {
		if (finish && haveChild)return false;
		for (int i = 0; i < ptr_num; i++) {
			if (child[i] && !child[i]->chk())return false;
		}
		return true;
	}
};



int main() {
	FIO;
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		Trie* root = new Trie;
		bool res = true;
		for (int i = 0; i < n; i++) {
			char num[11];
			cin >> num;
			root->insert(num);
		}
		if (root->chk())printf("YES\n");
		else printf("NO\n");
		delete root;
	}
	return 0;
}
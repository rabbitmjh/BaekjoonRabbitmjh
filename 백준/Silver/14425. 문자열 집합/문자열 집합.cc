#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int ptr_num = 26;

struct  Trie{
	Trie * child[ptr_num];
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
			int next = *key - 'a';
			if (!child[next])child[next] = new Trie;
			haveChild = true;
			child[next]->insert(key + 1);
		}
	}
    Trie* chk(const char * key) {
		if (*key == 0) return this;
		int next = char(*key) - 'a';
		if (child[next] == NULL) return NULL;
		return child[next]->chk(key + 1);
	}
};

int main() {
	int n,m; cin >> n>>m;
    Trie* root = new Trie;
    for(int i=0; i<n;i ++) {
        char s[505];
        scanf("%s",s);
        root->insert(s);
    }
    int cnt = 0;
    for(int i=0; i<m;i ++) {
        char s[501];
        scanf("%s",s);
		Trie *res = root->chk(s);
		if (res != NULL && res->finish)
			++cnt;;
    }
    cout << cnt;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int ptr = 96;
int num = 0;

struct Trie {
	Trie* child[ptr];
	int cnt;

	Trie() {
		fill(child, child + ptr, nullptr);
		cnt = false;
	}

	~Trie() {
		for (int i = 0; i < ptr; i++) if (child[i]) delete child[i];
	}

	void insert(char* key) {
		if (*key == '\0'){
			cnt++;
			return;
		}
		else {
			int next = *key - ' ';
			if (!child[next]) child[next] = new Trie;
			child[next]->insert(key + 1);
		}
	}
	void find(char *s, int d) {
		double percent = ((double)cnt / (double)num) * 100;
		if (cnt > 0) printf("%s %.4lf\n", s, percent);

		for (int i = 0; i < 96; i++) {
			if (child[i]) {
				s[d] = i + ' ';
				s[d + 1] = '\0';
				child[i]->find(s, d + 1);
			}
		}
	}
};

int main(){
	Trie* root = new Trie;
	char s[35];
	while (scanf("%[^\n]s", s) != EOF){
		getchar();
		num++;
		root->insert(s);
		memset(s, '\0', sizeof(s));
	}
	root->find(s, 0);

	return 0;
}
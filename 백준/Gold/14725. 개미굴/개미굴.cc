#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
struct Trie {
	map<string, Trie*> m;

	void insert(vector<string>& v, int idx) {
		if (idx == v.size())
			return;

		if (m.find(v[idx]) == m.end()) {
			Trie* trie = new Trie;
			m.insert({ v[idx], trie });
		}

		m[v[idx]]->insert(v, idx + 1);
	}

	void dfs(int d) {
		for (auto& i : m) {
			for (int j = 0; j < d; j++)
				cout << "--";
			cout << i.first << '\n';
			i.second->dfs(d + 1);
			delete i.second;
		}
	}
};

int main() {
    FIO;
	int n;
	cin >> n;

	Trie* root = new Trie;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		vector<string> v(num);
		for (int j = 0; j < num; j++)
			cin >> v[j];
		root->insert(v, 0);
	}

	root->dfs(0);
	delete root;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

struct TRIE {
    bool isEnd;
    map<string, TRIE*> Child;
    map<string, TRIE*>::iterator IT;

    TRIE() : isEnd(false) {}
    ~TRIE() {
        for (IT = Child.begin(); IT != Child.end(); IT++) {
            delete IT->second;
        }
    }

    void make_Directory(vector<string> Vec) {
        TRIE* NowTrie = this;

        for (int i = 0; i < Vec.size(); i++) {
            string Now = Vec[i];
            if (!NowTrie->Child[Now]) {
                NowTrie->Child[Now] = new TRIE;
            }
            NowTrie = NowTrie->Child[Now];
        }
        NowTrie->isEnd = true;
    }
};

int N, K;
string S;
vector<string> Directory;

vector<string> Split(string Str) {
    vector<string> Res;
    string tmp = "";
    for (int i = 0; i < Str.size(); i++) {
        if (Str[i] == '\\') {
            Res.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += Str[i];
        }
    }
    Res.push_back(tmp);

    return Res;
}

void DFS(TRIE* Trie, int Depth) {
    map<string, TRIE*>::iterator IT;
    for (IT = Trie->Child.begin(); IT != Trie->Child.end(); IT++) {
        for (int i = 0; i < Depth; i++) {
            cout << " ";
        }
        cout << IT->first << "\n";
        DFS(IT->second, Depth + 1);
    }
}

void find_Answer(TRIE* Root) {
    DFS(Root, 0);
}

void input() {
    TRIE* Root = new TRIE();
    cin >> N;
    while (N--) {
        Directory.clear();
        cin >> S;
        Directory = Split(S);
        Root->make_Directory(Directory);
    };
    find_Answer(Root);
    delete Root;
}

int main() {
    FIO;
    input();

    return 0;
}
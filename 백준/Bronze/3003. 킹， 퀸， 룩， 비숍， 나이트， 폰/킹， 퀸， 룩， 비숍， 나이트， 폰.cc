#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int king, queen, rook, bishop, knight, pawn;

int main() {
	FIO;

	cin >> king >> queen >> rook >> bishop >> knight >> pawn;

	cout << 1 - king << " " << 1 - queen << " " << 2 - rook << " " << 2 - bishop << " " << 2 - knight << " " << 8 - pawn;
	
	return 0;
}
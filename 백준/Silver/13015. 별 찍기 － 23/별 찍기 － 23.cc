#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;

void firstLast(int n) {
	for (int i = 0; i < n; i++)
		cout << "*";
	for (int i = 0; i < 1 + (n - 2) * 2; i++)
		cout << " ";
	for (int i = 0; i < n; i++)
		cout << "*";
	cout << "\n";
	return;
}
void downR(int n) {
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j < i; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < n - 2; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < 1 + (n - i - 2) * 2; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < n - 2; j++)
			cout << " ";
		cout << "*\n";
	}
	return;
}
void center(int n) {
	for (int i = 0; i < n - 1; i++)
		cout << " ";
	cout << "*";
	for (int j = 0; j < n - 2; j++)
		cout << " ";
	cout << "*";
	for (int j = 0; j < n - 2; j++)
		cout << " ";
	cout << "*\n";
	return;
}
void downL(int n) {
	for (int i = n - 2; i >= 1; i--) {
		for (int j = 0; j < i; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < n - 2; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < 1 + (n - i - 2) * 2; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < n - 2; j++)
			cout << " ";
		cout << "*\n";
	}
	return;
}

int main() {
	FIO;
	cin >> n;
	firstLast(n);
	downR(n);
	center(n);
	downL(n);
	firstLast(n);

	return 0;
}
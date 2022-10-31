#include<iostream>
#include<string>
using namespace std;
string word;
int arr[100], a = -1e9, j,b;
int sum;
int main() {
	getline(cin, word);
	for (int i = 0; i < word.size(); i++) {
		if (word[i] >= 97) {
			word[i] = word[i] - 32;
		}
		arr[word[i]]++;
		if (arr[word[i]]>a) {
			a = arr[word[i]];
			b = word[i];
		}
	}

	for (int i = 0; i < word.size(); i++) {
		if (a == arr[word[i]]) {
			j++;
		}
	}
		if (j > a) {
			printf("?");
		}
		else
			printf("%c", b);

	return 0;
}
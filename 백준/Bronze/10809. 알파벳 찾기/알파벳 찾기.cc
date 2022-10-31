#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
string word;
int arr[300] ;
int main() {
	cin >> word;
	memset(arr, -1,sizeof arr);
	for (int i = 0; i <= word.size(); i++) {
		if (arr[word[i] ] == -1) {
			arr[word[i] ] = i;
		}
	}
	for (int i = 0; i <= 25; i++) {
		printf("%d ", arr[i+97]);
	}
	return 0;
}
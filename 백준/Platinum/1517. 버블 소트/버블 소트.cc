#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
#define Max 500000

vector<int> v;
int N;
ll ans = 0;

void merge(int start, int mid, int end, int left, int right) {
	vector<int>temp;
	while (left <= mid && right <= end) {
		if (v[left] <= v[right]) {
			temp.push_back(v[left++]);
		}
		else {
			temp.push_back(v[right++]);
			ans += (mid + 1 - left);
		}
	}
	while (left <= mid) {
		temp.push_back(v[left++]);
	}
	while (right <= end) {
		temp.push_back(v[right++]);
	}
	for (int i = start, j = 0; i <= end; i++, j++) {
		v[i] = temp[j];
	}
}

void mergeSort(int start,int end) {
	int mid = (start + end) / 2;
	int l = start;
	int r = mid + 1;

	if (start == end)
		return;

	mergeSort(start, mid);
	mergeSort(mid + 1, end);

	merge(start, mid, end, l, r);
}

int main()  {
    FIO;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	mergeSort(0, N - 1);
	cout << ans << '\n';
	return 0;
}
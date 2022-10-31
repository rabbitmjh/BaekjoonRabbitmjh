#include <iostream>
using namespace std;

int n, idx = 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int cnt = 0;
    while (n--) {
        int num;
        cin >> num;
        if (num == idx)
            idx++;
        else
            cnt++;
    }
    cout << cnt;
}
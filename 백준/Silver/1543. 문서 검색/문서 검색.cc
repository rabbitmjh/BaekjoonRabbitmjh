#include <iostream>
#include <string>
using namespace std;
int main() {
   string str, str2;
   int ans = 0;
   getline(cin, str);
   getline(cin, str2);
   if (str.size() < str2.size()) {
      cout << 0 << endl;
      return 0;
   }
   for (int i = 0; i < str.size(); i++) {
      if (str[i] == str2[0] && str2.size()+i<=str.size()) {
         int cnt = 0;
         for (int j = 0; j < str2.length(); j++) {
            if (str[i + j] == str2[j]) cnt++;
         }
         if (cnt == str2.length()) {
            ans++;
            i += str2.length()-1;
         }
      }
   }
   cout << ans << endl;
   return 0;
}
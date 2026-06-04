#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int ma = -INT_MAX;
    int mi = INT_MAX;
    for(int i=0;i<s.size();i++)
    {
        string tmp="";
        int j=i;
        while(s[j]!=' ')
        {
            tmp+=s[j];
            j++;
        }
        ma = max(stoi(tmp),ma);
        mi = min(stoi(tmp),mi);
        i=j;
    }
    answer =to_string(mi)+" "+to_string(ma);
    return answer;
}
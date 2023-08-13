#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> v;
    map<string, string> user;
    
    for (int i = 0;i < record.size();i++) {
        int cnt = 0;
        string state, uid, name;

        for (int j = 0;j < record[i].size();j++) {
            if (record[i][j] == ' ') {
                cnt++;
                continue;
            }
            else {
                if (cnt == 0)state += record[i][j];
                else if (cnt == 1)uid += record[i][j];
                else if (cnt == 2)name += record[i][j];
            }
        }
        vector<string>tmp;
        tmp.push_back(state);
        tmp.push_back(uid);
        tmp.push_back(name);
        v.push_back(tmp);
        
        if (state == "Enter" || state == "Change") {
            user[uid] = name;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i][0] == "Enter") {
            answer.push_back(user[v[i][1]] + "님이 들어왔습니다.");
        }
        else if(v[i][0] == "Leave") {
            answer.push_back(user[v[i][1]] + "님이 나갔습니다.");
        }
    }
    return answer;
}
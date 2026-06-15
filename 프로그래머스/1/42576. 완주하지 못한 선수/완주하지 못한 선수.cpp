#include <string>
#include <vector>
#include <unordered_map>


using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> ans;
    for (int i = 0; i < participant.size(); i++)
    {
        auto it = ans.find(participant[i]);
        if (it == ans.end())
        {
            ans.insert({ participant[i], 1 });
        }
        else
        {
            (*it).second++;
        }
    }
    for (int i = 0; i < completion.size(); i++)
    {
        auto it = ans.find(completion[i]);
        if (it != ans.end())
        {
            (*it).second--;
        }
    }

    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        if ((*it).second > 0)
        {
            answer = (*it).first;
            break;
        }
    }
    return answer;
    
}
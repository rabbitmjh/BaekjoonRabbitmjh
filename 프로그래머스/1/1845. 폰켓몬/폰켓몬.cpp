#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> um;

    for (int i = 0; i < nums.size(); i++)
    {
        auto it = um.find(nums[i]);
        if (it == um.end())
        {
            um.insert({ nums[i],1 });
        }
        else
        {
            (*it).second++;
        }
    }

    if (nums.size() / 2 <= um.size())
        answer = nums.size() / 2;
    else
        answer = um.size();

    return answer;
}
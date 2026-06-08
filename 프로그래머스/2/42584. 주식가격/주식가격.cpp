#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> st;
    answer.resize(prices.size());

    for (int i = 0; i < prices.size(); i++)
    {
        if (!st.empty())
        {
            int highprice = st.top().first;
            if (highprice <= prices[i])
                st.push({ prices[i],i });
            else
            {
                while (highprice > prices[i])
                {
                    highprice = st.top().first;
                    int idx = st.top().second;

                    if (prices[i] < highprice)
                    {
                        answer[idx] = i - idx;
                        st.pop();
                    }
                    if (st.empty())
                        break;
                }
                st.push({ prices[i],i });
            }
        }
        else
            st.push({ prices[i],i });
    }
    while (!st.empty())
    {
        int idx = st.top().second;
        answer[idx] = prices.size() - 1 - idx;
        st.pop();
    }
    return answer;
}
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int last = -1, maxCnt = 0;
        int len = s.size();
        if (len <= 1)
            return maxCnt;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                if (stk.empty())
                    last = i;
                else
                {
                    stk.pop();
                    if (stk.empty())
                        maxCnt = max(maxCnt, i - last);
                    else maxCnt = max(maxCnt, i - stk.top());
                }
            }
        }
        return maxCnt;
    }
};
int main()
{
    string str = "(())(())(()))";
    Solution s;
    cout << s.longestValidParentheses(str);
    return 0;
}

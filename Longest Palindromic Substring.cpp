#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), max = 1, ss = 0, tt = 0;
        bool flag[len][len];
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                if (i >= j)
                    flag[i][j] = true;
                else flag[i][j] = false;
        for (int j = 1; j < len; j++)
            for (int i = 0; i < j; i++)
            {
                if (s[i] == s[j])
                {
                    flag[i][j] = flag[i+1][j-1];
                    if (flag[i][j] == true && j - i + 1 > max)
                    {
                        max = j - i + 1;
                        ss = i;
                        tt = j;
                    }
                }
                else flag[i][j] = false;
            }
        return s.substr(ss, max);
    }
};
int main()
{
    Solution s;
    cout << s.longestPalindrome("babcbabcbaccba");
    return 0;
}

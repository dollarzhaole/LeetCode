#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    static string tbl[8];
//    Solution()
//    {
//        tbl[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//    }
    void dfs(vector<string> &v, int n, int i, string digits, string cur)
    {
        string str = tbl[digits[i]-'2'];
        int len = str.length();
        for (int j = 0; j < len; j++)
        {
            string next = cur + str[j];
            if (i == n-1)
                v.push_back(next);
            else dfs(v, n, i+1, digits, next);
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = digits.length();
        vector<string> v;
        if (len <= 0)
        {
            v.push_back("");
            return v;
        }

        dfs(v, len, 0, digits, "");
        return v;
    }
};
string Solution::tbl[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int main()
{
    string str = "23";
    Solution s;
    vector<string> v = s.letterCombinations(str);
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << endl;
    return 0;
}

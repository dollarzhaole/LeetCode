#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
//bool cmp(string a, string b)
//{
//    int la = a.length(), lb = b.length();
//    int i = 0, j = 0;
//    while (a[i] == a[j] && i < la && j < lb)
//    {
//        i++;
//        j++;
//    }
//    if (i == la && j != lb)
//        return true;
//    else if (i != la && j == lb)
//        return false;
//    else if (i == la && j == lb)
//        return true;
//    else return a[i] < a[j];
//}
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string rst = "";
        if (strs.size() == 0)
            return rst;
        if (strs.size() == 1)
            return strs[0];
        int size = strs.size();
        int k = 0;
        while (1)
        {
            char c = strs[0][k];
            for (int i = 0; i < size; i++)
            {
                if (strs[i][k] != c || k >= strs[i].length())
                    return rst;
            }
            rst += c;
            k++;
        }
        return rst;
    }
};
int main()
{
    Solution s;
    vector<string> v;
    v.push_back("flower");
    v.push_back("flow");
    v.push_back("flight");
    cout << s.longestCommonPrefix(v);
    return 0;
}

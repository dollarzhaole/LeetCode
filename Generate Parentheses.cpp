#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(int l, int r, int n, string str, vector<string> &v)
    {
        if (r == n)
        {
            v.push_back(str);
            return;
        }
        if (l > r)
            dfs(l, r + 1, n, str + ')', v);
        if (l < n)
            dfs(l + 1, r, n, str + '(', v);
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> rst;
        string str = "";
        dfs(0, 0, n, str, rst);
        return rst;
    }
};
int main()
{

    return 0;
}

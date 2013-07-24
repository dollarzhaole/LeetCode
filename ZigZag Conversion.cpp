#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (nRows <= 1)
            return s;
        int zigSize = nRows * 2 - 2;
        string rst = "";
        for (int i = 0; i < nRows; i++)
        {
            for (int j = i; j < s.length(); j += zigSize)
            {
                rst += s[j];
                if (i > 0 && i < nRows - 1)
                {
                    if (j+zigSize-2*i < s.length())
                        rst += s[j+zigSize-2*i];
                }
            }
        }
        return rst;
    }
};
int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3);
    return 0;
}

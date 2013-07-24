#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int atoi(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        string rst = "";
        while (s[i] == ' ')
            i++;
        if (s[i] == '+' || s[i] == '-')
            rst += s[i], i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            rst += s[i];
            i++;
        }
        return getInt(rst);
    }
    int getInt(string s)
    {
        if (s == "" || s == "+" || s == "-")
            return 0;
        if (s[0] == '+')
        {
            return strtoi(s.substr(1, s.length()-1), 1);
        } else if (s[0] == '-')
        {
            return -strtoi(s.substr(1, s.length()-1), 0);
        } else
        {
            return strtoi(s, 1);
        }
    }
    int strtoi(string s, int flag)
    {
        int len = s.length();
        long long rst = 0;
        for (int i = 0; i < len; i++)
        {
            rst += (s[len-1-i] - '0')  * pow(10, i);
        }
        if (rst > 2147483647 && flag == 1)
            return 2147483647;
        else if (rst > 2147483648 && flag == 0)
            return 2147483648;
        else return (int)rst;
    }
};
int main()
{
//    Solution s;
    const char *c = "-2147483648";
    const char *a = "abc";
    char *const p = "abcdef";
    *p = "m";
    cout << c << endl << a << endl << p << endl;
//    cout << s.atoi(c);
    return 0;
}

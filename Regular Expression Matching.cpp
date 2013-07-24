#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ls = strlen(s);
        int lp = strlen(p);
        if (lp == 0)
        {
            if (ls != 0) return false;
            else return true;
        }
        if (lp >= 2 && p[1] == '*')
        {
            int i = 0;
            if (isMatch(s, p+2))
                return true;

            while (s[i] == p[0] || p[0] == '.')
            {
                if (isMatch(s+i+1, p+2))
                    return true;
                i++;
                if (i >= ls)
                    break;
            }
        }
        else
        {
            if (ls > 0 && (s[0] == p[0] || p[0] == '.'))
                return isMatch(s+1, p+1);
        }
        return false;
    }
};
int main()
{

    return 0;
}

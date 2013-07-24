#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = getLen(x);
        int rst = 0;
        for (int i = 1; i <= len; i++)
        {
            int t = x % 10;
            x = x / 10;
            int a = len - i, temp = 1;
            while (a > 0)
            {
                temp = temp * 10;
                a--;
            }
            rst += t * temp;
        }
        return rst;
    }
    int getLen(int x)
    {
        int len = 0, t = x;
        while (t)
        {
            t = t / 10;
            len += 1;
        }
        return len;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(-12345);

    return 0;
}

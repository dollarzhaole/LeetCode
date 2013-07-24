#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
            return false;
        int div = 1, t = x;
        while (x / div >= 10)
            div *= 10;
        while (div != 1)
        {
            if (x / div == t % 10)
            {
                x = x % div;
                div /= 10;
                t = t / 10;
            } else
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    cout << s.isPalindrome(32);
    return 0;
}

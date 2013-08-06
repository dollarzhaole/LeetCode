#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    unsigned int unsDivide(unsigned int &dividend, unsigned int divisor)
    {
        if (dividend < divisor)
        {
            dividend = 0;
            return 0;
        }

        unsigned int result = 1;

        while (divisor < dividend)
        {
            divisor <<= 1;
            result <<= 1;
        }

        if (divisor != dividend)
        {
            divisor >>= 1;
            result >>= 1;
        }

        dividend -= divisor;

        return result;
    }

    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool neg = ((dividend > 0 && divisor < 0) || (dividend > 0 && divisor < 0));
        unsigned int udividend = dividend < 0 ? -dividend : dividend;
        unsigned int udivisor = divisor < 0 ? -divisor : divisor;
        unsigned int result = 0;

        while (udividend != 0)
        {
            result += unsDivide(udividend, udivisor);
        }
        return neg ? -(int)result : (int)result;
    }
};
int main()
{

    return 0;
}

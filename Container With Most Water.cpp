#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = height.size() - 1;

        int rst = 0, h;
        while (i < j)
        {
            rst = max(rst, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return rst;
    }
};
int main()
{
    Solution s;
    cout << s.maxArea()
    return 0;
}

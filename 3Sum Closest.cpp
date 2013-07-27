#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() == 3)
            return (num[0] + num[1] + num[2]);
        sort(num.begin(), num.end());
        int size = num.size();
        int rst = num[0] + num[1] + num[2];//刚开始这里没有赋初值，结果当num={1,1,1,1}的时候总是出错，是因为进不到while循环里的第二个if中，rst就没有初值，所以以后还是声明变量的时候要赋初值
        int dif = abs(num[0] + num[1] + num[2] - target);
        int sum;
        for (int i = 0; i < size - 2; i++)
        {
            int j = i + 1, k = size - 1;
            while (j < k)
            {
                sum = num[i] + num[j] + num[k];
                if (sum == target)
                    return sum;
                if (abs(sum-target) < dif)
                {
                    dif = abs(sum-target);
                    rst = sum;
                }
                if (sum > target)
                    k--;
                else j++;
            }
        }
        return rst;
    }
};
int main()
{
    int a[4] = {1,1,1,1};
    vector<int> v;
    for (int i = 0; i < 4; i++)
        v.push_back(a[i]);
    Solution s;
    cout << s.threeSumClosest(v, 0);
    return 0;
}

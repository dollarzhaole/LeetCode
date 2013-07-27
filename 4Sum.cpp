#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rst;
        if (num.size() < 4) return rst;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; i++)
        {
            if (i > 0 && num[i] == num[i-1])
                continue;
            for (int j = i+1; j < num.size() - 2; j++)
            {
                if (j > i + 1 && num[j] == num[j-1]) continue;
                int t = num.size() - 1;
                for (int k = j + 1; k < t; k++)
                {
                    if (k > j + 1 && num[k] == num[k-1])
                    {
                        continue;
                    }
                    int sum = num[i] + num[j] + num[k] + num[t];
                    if (sum == target)
                    {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[k]);
                        v.push_back(num[t]);
                        rst.push_back(v);
                    } else if (sum > target)
                        t--, k--;
                }
            }
        }
        return rst;
    }
};
int main()
{

    return 0;
}

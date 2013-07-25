#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a, int b)
{
    return a < b;
}
class Solution {
public:
    vector<int> getThree(int a, int b, int c)
    {
        vector<int> v;
        if (a < c && b < c)
        {
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
        }
        else if (a < c && b > c)
        {
            v.push_back(a);
            v.push_back(c);
            v.push_back(b);
        }
        else
        {
            v.push_back(c);
            v.push_back(a);
            v.push_back(b);
        }
        return v;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end(), cmp);
        vector<int> three;
        vector<vector<int> > rst;
        for (int i = 0; i < num.size(); i++)
        {
            int t = -num[i];
            int m = i+1, n = num.size() - 1;
            while (m < n)
            {
//                if (m == i)
//                {
//                    m++;
//                    continue;
//                }
//                if (n == i)
//                {
//                    n--;
//                    continue;
//                }
                if (num[m] + num[n] == t)
                {
                    three = getThree(num[m], num[n], -t);
                    rst.push_back(three);
                    m++;
                    while (m < n && num[m-1] == num[m]) m++;
                    n--;
                    while (m < n && num[n+1] == num[m]) n--;
                } else if (num[m] + num[n] < t)
                {
                    m++;
                    while (m < n && num[m-1] == num[m]) m++;
                } else if (num[m] + num[n] > t)
                {
                    n--;
                    while (m < n && num[n+1] == num[m]) n--;
                }
            }
            while (num[i] == num[i+1] && i+1 < num.size())
                i++;
        }
        return rst;
    }
};
int main()
{
    Solution s;
    vector<int> v;
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-1);
    v.push_back(-4);
    vector<vector<int> > rst = s.threeSum(v);

    return 0;
}

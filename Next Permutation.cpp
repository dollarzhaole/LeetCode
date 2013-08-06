#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size(), j, i = 0;
        for (i = len - 1; i > 0; i--)
        {
            if (num[i] <= num[i-1])
                continue;
            else    break;
        }

        if (i != 0)
        {
            int change1 = i - 1;
            for (j = len - 1; j > 0; j--)
            {
                if (num[j] > num[change1])
                    break;
            }
            int change2 = j;
            swap(num[change1], num[change2]);
        }
        reverse(num.begin() + i, num.end());
    }
};
int main()
{
    int a[] = {3, 2, 1};
    vector<int> v;
    for (int i = 0; i < 3; i++)
        v.push_back(a[i]);
    Solution s;
    s.nextPermutation(v);
    for (int i = 0; i < 3; i++)
        cout << v[i] << endl;
    return 0;
}

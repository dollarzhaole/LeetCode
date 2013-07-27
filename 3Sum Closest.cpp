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
        int rst = num[0] + num[1] + num[2];//�տ�ʼ����û�и���ֵ�������num={1,1,1,1}��ʱ�����ǳ�������Ϊ������whileѭ����ĵڶ���if�У�rst��û�г�ֵ�������Ժ�������������ʱ��Ҫ����ֵ
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

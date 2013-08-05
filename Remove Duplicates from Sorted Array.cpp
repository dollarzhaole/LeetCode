#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return 0;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (A[i] == A[i-1])
                continue;
            else
            {
                A[cnt] = A[i];
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    int a[] = {1, 1, 3, 5, 6, 6, 6, 7, 8, 8};
    Solution s;
    cout << s.removeDuplicates(a, 10);
    return 0;
}

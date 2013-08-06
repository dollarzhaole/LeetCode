#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findLeft(int a[], int l, int r, int target)
    {
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (a[m] < target)
                l = m + 1;
            else r = m;
//            cout << l << endl;
        }
        return l;
    }
    int findRight(int a[], int l, int r, int target)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (a[m] > target)
                r = m - 1;
            else l = m + 1;
        }
        return r;
    }
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0, r = n - 1;
        vector<int> v(2, -1);
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (A[m] > target)
                r = m - 1;
            else if (A[m] < target)
                l = m + 1;
            else
            {
                v[0] = findLeft(A, l, m, target);
                v[1] = findRight(A, m, r, target);
                break;
            }
        }
        return v;
    }
};
int main()
{
//    int a[] = {5, 6, 8, 8, 9, 10};
    int a[] = {1};
    int t = 1;
    Solution s;
//    cout << s.findLeft(a, 0, 2, 8);
//    cout << s.findRight(a, 2, 5, 8);
    vector<int> v = s.searchRange(a, 1, t);
    cout << v[0] << endl;
    cout << v[1] << endl;
    return 0;
}

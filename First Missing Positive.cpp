#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0, j;
        while (i < n)
        {
            if (A[i] != i + 1 && A[i] > 0 && A[i] <= n && A[i] != A[A[i]-1])
                swap(A[i], A[A[i]-1]);
            else i++;
        }

        for (j = 0; j < n; j++)
            if (A[j] != j + 1)
                return j + 1;
        return n + 1;
    }
};
int main()
{

    return 0;
}

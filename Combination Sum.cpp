#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> temp;
        vector<vector<int> > rst;
        sort(candidates.begin(), candidates.end());//[8,7,4,3], 11	[[8,3],[7,4],[4,4,3]]	[[3,4,4],[3,8],[4,7]]
        dfs(candidates, target, temp, rst, 0);
        return rst;
    }
    void dfs(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int> > &rst, int pos)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            rst.push_back(temp);
            return;
        }

        for (int i = pos; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], temp, rst, i);
            temp.pop_back();
        }
    }
};
int main()
{

    return 0;
}

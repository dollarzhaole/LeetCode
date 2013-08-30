#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        int n = strs.size();
        map<string, int> m;
        vector<string> rst;
        for (int i = 0; i < n; i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (m.find(str) == m.end())
            {
                m.insert(make_pair(str, i));
            }
            else
            {
                if (m[str] >= 0)
                {
                    rst.push_back(strs[m[str]]);
                    m[str] = -1;
                }
                rst.push_back(strs[i]);
            }
        }
        return rst;
    }
};
int main()
{

    return 0;
}

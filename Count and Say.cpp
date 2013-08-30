#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0)
            return "";
        if (n == 1)
            return "1";
        string say = "1";
        stringstream ss;
        for (int i = 1; i < n; i++)
        {
            char temp = say[0];
            int cnt = 0;
            ss.str("");
            for (int j = 0; j <= say.size(); j++)
            {
                if (say[j] == temp)
                    cnt++;
                else
                {
                    ss << cnt << temp;
                    cnt = 1;
                    temp = say[j];
                }
            }
            say = ss.str();
        }
        return ss.str();
    }
};

int main()
{
    Solution s;
//    for (int i = 1; i < 5; i++)
        cout << s.countAndSay(6) << endl;
    return 0;
}

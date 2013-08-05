#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

void getNext(char *str, int next[])
{
    int len = strlen(str), i = 0, j = 0;
    next[0] = 0;
    for (i = 1; i < len; i++)
    {
        while (j != 0 && str[i] != str[j])
            j = next[j - 1];
        if (str[i] == str[j])
            j++;
        next[i] = j;
    }
}

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int nlen = strlen(needle), hlen = strlen(haystack);
        if (nlen == 0 && hlen == 0)
            return "";
        else if (nlen == 0)
            return haystack;
        int next[nlen];
        getNext(needle, next);
        return getKMP(haystack, needle, next);
    }
    char *getKMP(char *haystack, char *needle, int next[]) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hlen = strlen(haystack), nlen = strlen(needle);
        int i, j = 0;
        for (i = 0; i < hlen; i++)
        {
            while (j != 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == nlen)
                return haystack + (i - j + 1);
        }
        return NULL;
    }
};
int main()
{
    char str[] = "abaabcac";
    int len = strlen(str);
    int next[len];
    getNext(str, next);
    for (int i = 0; i < len; i++)
        cout << str[i] << ' ' << next[i] << endl;
    return 0;
}

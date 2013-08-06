#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || k <= 1)
            return head;
        int len = k - 1;
        ListNode *p = head;
        while (p->next != NULL && len > 0)
        {
            len--;
            p = p->next;
        }
        if (len > 0)
            return head;

        ListNode *pPrev = head;
        ListNode *pCur = pPrev->next;
        while (pCur != p)
        {
            ListNode *pNext = pCur->next;
            pCur->next = pPrev;
            pPrev = pCur;
            pCur = pNext;
        }
        ListNode *newHead = reverseKGroup(p->next, k);
        pCur->next = pPrev;
        head->next = newHead;
        head = p;
        return head;
    }
};
int main()
{

    return 0;
}

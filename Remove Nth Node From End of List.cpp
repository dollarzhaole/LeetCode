#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)   return head;
        ListNode *first = head, *second = head;
        while (n > 1 && first != NULL)
        {
            first = first->next;
            n--;
        }
        if (n > 1 || first == NULL) return head;
        if (first->next == NULL) //这个条件把我困住了很久~~~~
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode *prev;
        while (first->next != NULL)
        {
            prev = second;
            first = first->next;
            second = second->next;
        }
        prev->next = second->next;
        delete second;
        return head;
    }
};
int main()
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p = head;
    p->val = 1;
    p->next = NULL;
//    for (int i = 2; i < 6; i++)
//    {
//        ListNode *t = (ListNode*)malloc(sizeof(ListNode));
//        t->val = i;
//        t->next = NULL;
//        p->next = t;
//        p = t;
//    }


    Solution s;
    s.removeNthFromEnd(head, 1);
//    p = head;
//    while (p != NULL)
//    {
//        cout << p->val << ' ' <<  p << ' ' << p->next << endl;
//        p = p->next;
//    }
    return 0;
}

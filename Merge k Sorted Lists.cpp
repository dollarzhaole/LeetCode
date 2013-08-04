#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};
//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode *> &lists)
//    {
//        int len = lists.size();
//        if (len == 0)
//            return NULL;
//        if (len == 1)
//            return lists[0];
//        ListNode *head = (ListNode*)malloc(sizeof(ListNode));
//        ListNode *p = head;
//        ListNode *t = NULL;
//        while (true)
//        {
//            int cnt = 0;
//            int minVal = 0x0FFFFFFF;
//            for (int i = 0; i < len; i++)
//            {
//                if (lists[i] == NULL)
//                {
//                    cnt++;
//                    lists.erase(lists.begin() + i);
//                    continue;
//                }
//                if (minVal > lists[i]->val)
//                {
//                    minVal = lists[i]->val;
//                    t = lists[i];
//                    p->next = lists[i];
//                }
//            }
//            if (cnt == len - 1)
//                break;
//            len = len - cnt;
//            p = p->next;
//            t = t->next;
//        }
//        return head->next;
//    }
//};
bool cmp(ListNode* a, ListNode* b)
{
    return a->val > b->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode*>::iterator it = lists.begin();
        while (it != lists.end())//为了保证vector中的链表都不是空链表
        {
            if (*it == NULL)
                lists.erase(it);
            else it++;
        }

        if (lists.size() < 1)
            return NULL;

        ListNode *head = NULL, *cur = NULL;
        make_heap(lists.begin(), lists.end(), cmp);

        while (lists.size() > 0)
        {
            if (head == NULL)
                head = cur = lists[0];
            else
                cur = cur->next = lists[0];

            pop_heap(lists.begin(), lists.end(), cmp);
            int last = lists.size() - 1;
            if (lists[last]->next != NULL)
            {
                lists[last] = lists[last]->next;
                push_heap(lists.begin(), lists.end(), cmp);
            }
            else lists.pop_back();
        }

        return head;
    }
};
int main()
{
//    int a[] = {10, 40, 14, 20, 30};
//    vector<int> v;
//    for (int i = 0; i < 5; i++)
//        v.push_back(a[i]);
//    make_heap(v.begin(), v.end(), cmp);
//    pop_heap(v.begin(), v.end());
////    v.pop_back();
//    for (int i = 0; i < v.size(); i++)
//        cout << v[i] << endl;
    return 0;
}

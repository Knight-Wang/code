#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int K = lists.size();
        if (!K) return NULL;
        return merge(lists, 0, K - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r) return lists[l];
        else
        {
            int m = l + r >> 1;
            ListNode* x = merge(lists, l, m);
            ListNode* y = merge(lists, m + 1, r);
            return merge2Lists(x, y);
        }
    }
    ListNode* merge2Lists(ListNode* a, ListNode* b)
    {
        ListNode* t = NULL;
        ListNode* ans = NULL;
        while (a && b)
        {
            if (a->val < b->val)
            {
                if (!t) { t = new ListNode(a->val); ans = t; }
                else { t->next = new ListNode(a->val); t = t->next; }
                a = a->next;
            }
            else
            {
                if (!t) { t = new ListNode(b->val); ans = t; }
                else { t->next = new ListNode(b->val); t = t->next; }
                b = b->next;
            }
        }
        while (a)
        {
            if (!t) { t = new ListNode(a->val); ans = t; }
            else { t->next = new ListNode(a->val); t = t->next; }
            a = a->next;
        }
        while (b)
        {
            if (!t) { t = new ListNode(b->val); ans = t; }
            else { t->next = new ListNode(b->val); t = t->next; }
            b = b->next;
        }
        return ans;
    }
};

int main()
{
    vector<ListNode*> lists(3, NULL);
    lists[0] = new ListNode(1);
    lists[0]->next = new ListNode(4);
    lists[0]->next->next = new ListNode(5);
    lists[1] = new ListNode(1);
    lists[1]->next = new ListNode(3);
    lists[1]->next->next = new ListNode(4);
    lists[2] = new ListNode(2);
    lists[2]->next = new ListNode(6);
    ListNode* ans = Solution().mergeKLists(lists);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
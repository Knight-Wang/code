/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head) return false;
        ListNode *p = head, *q = head;
        while (p && q)
        {
            if (!p->next || !p->next->next) break;
            p = p->next->next;
            q = q->next;
            if (p == q) return true;
        }
        return false;
    }
};

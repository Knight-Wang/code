/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2) return NULL;
        ListNode* res = new ListNode(0), *a = l1, *b = l2, *t = res;
        while (a && b)
        {
            if (a->val < b->val) { t->val = a->val; a = a->next; }
            else { t->val = b->val; b = b->next; }
            if (a || b) { t->next = new ListNode(0); t = t->next; }
        }
        while (a)
        {
            t->val = a->val; a = a->next;
            if (a) { t->next = new ListNode(0); t = t->next;}
        }
        while (b)
        {
            t->val = b->val; b = b->next;
            if (b) { t->next = new ListNode(0); t = t->next;}
        }
        return res;
    }
};